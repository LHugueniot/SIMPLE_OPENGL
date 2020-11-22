#include "Camera.h"

void setMatToProjection(Eigen::Matrix4f & projMat,
                        float windowWidth, 
                        float windowHeight, 
                        float fov, 
                        float far, float near){

    projMat.setIdentity();
    float aspect = float(windowWidth)/float(windowHeight);
    float theta = fov * .5f;
    float range = far - near;
    float invtan = 1.f/tan(theta);

    projMat(0,0) = invtan / aspect;
    projMat(1,1) = invtan;
    projMat(2,2) = -(near + far) / range;
    projMat(3,2) = -1;
    projMat(2,3) = -2 * near * far / range;
    projMat(3,3) = 0;
}

Camera::Camera(float _windowWidth, 
               float _windowHeight,
               float _fov, 
               float _far, 
               float _near,

               float _yaw,
               float _pitch,
               float _zoom,
               float _rotationSpeed, 
               float _zoomSpeed,

               Eigen::Vector3f _eyePos,
               Eigen::Vector3f _targetPos) :

        m_windowWidth(_windowWidth),
        m_windowHeight(_windowHeight),
        m_fov(_fov),
        m_far(_far), 
        m_near(_near),

        m_yaw(_yaw),
        m_pitch(_pitch),
        m_zoom(_zoom),
        m_rotationSpeed(_rotationSpeed),
        m_zoomSpeed(_zoomSpeed),

        m_eyePos(_eyePos),
        m_targetPos(_targetPos) {

    setMatToProjection(m_projMat, m_windowWidth, 
        m_windowHeight, m_fov, m_far, m_near);
}
void Camera::updateProjMat(){

    setMatToProjection(m_projMat, m_windowWidth, 
        m_windowHeight, m_fov, m_far, m_near);
}

void Camera::updateProjMat(float windowWidth,
    float windowHeight, float fov, float far, float near){

    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    m_fov = fov;
    m_far = far;
    m_near = near;

    setMatToProjection(m_projMat, m_windowWidth, 
        m_windowHeight, m_fov, m_far, m_near);
}

void Camera::yaw(float yawAngle){
    m_yaw -= yawAngle;

    if (m_yaw > M_PI)
        m_yaw -= 2.0 * M_PI;
    else if (m_yaw < -M_PI)
        m_yaw += 2.0 * M_PI;
}

void Camera::pitch(float pitchAngle){
    m_pitch = std::clamp(m_pitch + pitchAngle, - .5f * (float)M_PI, .5f * (float)M_PI);
}

void Camera::zoom(float zoomAmount){
    m_zoom = std::clamp(m_zoom + zoomAmount, 0.f, 10.f);
}

void Camera::move(Camera::Actions action){
    switch (action){
        case Camera::ORBIT_LEFT:
            yaw(m_rotationSpeed);
            break;
        case Camera::ORBIT_RIGHT:
            yaw(-m_rotationSpeed);
            break;
        case Camera::ORBIT_UP:
            pitch(-m_rotationSpeed);
            break;
        case Camera::ORBIT_DOWN:
            pitch(m_rotationSpeed);
            break;
        case Camera::ZOOM_IN:
            zoom(m_zoomSpeed);
            break;
        case Camera::ZOOM_OUT:
            zoom(-m_zoomSpeed);
            break;
    }
}

void Camera::setLookAt(Eigen::Vector3f const & position,
    Eigen::Vector3f const & target, Eigen::Vector3f const & up){
    m_targetPos = target;
    m_eyePos = position;

    Eigen::Matrix3f R;
    R.col(2) = (m_eyePos - m_targetPos).normalized();
    R.col(0) = up.cross(R.col(2)).normalized();
    R.col(1) = R.col(2).cross(R.col(0));
    m_viewMat.topLeftCorner<3,3>() = R.transpose();
    m_viewMat.topRightCorner<3,1>() = -R.transpose() * m_eyePos;
    m_viewMat(3,3) = 1.0f;
}

void Camera::update(){
    Eigen::Matrix3f R_yaw;
    R_yaw = Eigen::AngleAxisf(m_yaw, Eigen::Vector3f::UnitY());
    Eigen::Matrix3f R_pitch;
    R_pitch = Eigen::AngleAxisf(m_pitch, Eigen::Vector3f::UnitX());
    m_eyePos = (R_yaw * R_pitch * (m_zoom * (m_eyePos - m_targetPos))) + m_targetPos;
    setLookAt(m_eyePos, m_targetPos, Eigen::Vector3f(0, 1, 0));
}
