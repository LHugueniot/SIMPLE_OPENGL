#ifndef CAMERA_H
#define CAMERA_H

#include "Common.h"

void setMatToProjection(Eigen::Matrix4f & projMat,
                        float windowWidth,
                        float windowHeight,
                        float fov,
                        float far,
                        float near);

struct Camera{

    enum Actions{
        ORBIT_LEFT,
        ORBIT_RIGHT,
        ORBIT_UP,
        ORBIT_DOWN,
        ZOOM_IN,
        ZOOM_OUT
    };

    Camera(float _windowWidth, 
           float _windowHeight,
           float _fov = TO_RAD(50),
           float _far = 200.f,
           float _near = 1.f,

           float _yaw = 0.f,
           float _pitch = 0.f,
           float _zoom = 1.f,
           float _rotationSpeed = 0.05f,
           float _zoomSpeed = 0.05f,

           Eigen::Vector3f _eyePos = {0.f, 0.f, 30.f},
           Eigen::Vector3f _targetPos = {0.f, 0.f, 0.f});

    void updateProjMat();

    void updateProjMat(float windowWidth, float windowHeight,
        float fov, float far, float near);

    void yaw(float yawAngle);
    void pitch(float pitchAngle);
    void zoom(float zoomAmount);
    void move(Camera::Actions action);

    void setLookAt(Eigen::Vector3f const & position,
        Eigen::Vector3f const & target, Eigen::Vector3f const & up);

    void setLookAt(Eigen::Matrix4f & viewMat,
                  Eigen::Vector3f const & position,
                  Eigen::Vector3f const & target,
                  Eigen::Vector3f const & up);

    void update();

    // Perspective Parameters (used for m_projMat)
    float m_windowWidth,
          m_windowHeight,
          m_fov,
          m_far,
          m_near;

    // Trackball parameters (used for m_viewMat)
    float m_yaw, 
          m_pitch,
          m_zoom,
          m_rotationSpeed,
          m_zoomSpeed;

    // Stored camera positions (used for m_viewMat)
    Eigen::Vector3f m_eyePos, m_targetPos;

    // View matrix (camera transform)
    // Projection matrix (perspective)
    Eigen::Matrix4f m_viewMat, m_projMat;
};


#endif /* CAMERA_H */
