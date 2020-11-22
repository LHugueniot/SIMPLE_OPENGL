#include "Kernel.h"

bool Kernel::init(uint _windowWidth, uint _windowHeight, std::string const & _windowName){
    m_windowWidth = _windowWidth;
    m_windowHeight = _windowHeight; 
    m_windowName = _windowName;

    std::atexit(SDL_Quit);

    if (SDL_Init(SDL_INIT_VIDEO)<0 ){
        std::cout<<"Failed to init SDL: "<<SDL_GetError()<<std::endl;
        m_isInitialized = false;
        return false;
    }

    //SDL_GL_LoadLibrary(0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, 
               SDL_GL_CONTEXT_PROFILE_CORE);

    //SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    //SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    //SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    m_window = SDL_CreateWindow(m_windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                m_windowWidth, m_windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(!m_window){
        std::cout<<"Failed to create window: "<<SDL_GetError()<<std::endl;
        m_isInitialized = false;
        return false;
    }

    m_context = SDL_GL_CreateContext(m_window);
    if(!m_context){
        std::cout<<"Failed to create GL context: "<<SDL_GetError()<<std::endl;
        m_isInitialized = false;
        return false;
    }

    GLenum err = glewInit();
    if (GLEW_OK != err){
        // GLEW failed!
        std::cout<<"Failed to unit GLEW: "<<glewGetErrorString(err)<<std::endl;
        m_isInitialized = false;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(m_window && m_context)
        SDL_GL_SwapWindow(m_window);



    m_isInitialized = true;
    return m_isInitialized;
}

bool Kernel::teardown(){

    if(m_isInitialized){

        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        m_isInitialized = false;
        return true;
    }

    return false;
}

void Kernel::run(){
    bool quit = false;

    while(!quit){

        SDL_Event event;

        while (SDL_PollEvent(&event) != 0){

            switch (event.type){

                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_KEYDOWN:

                    switch(event.key.keysym.sym){

                    case SDLK_LEFT:
                        m_viewerCamera->move(Camera::ORBIT_LEFT);
                        std::cout<<"SDLK_LEFT"<<std::endl;
                        break;

                    case SDLK_RIGHT:
                        m_viewerCamera->move(Camera::ORBIT_RIGHT);
                        std::cout<<"SDLK_RIGHT"<<std::endl;
                        break;

                    case SDLK_UP:
                        m_viewerCamera->move(Camera::ORBIT_UP);
                        std::cout<<"SDLK_UP"<<std::endl;
                        break;

                    case SDLK_DOWN:
                        m_viewerCamera->move(Camera::ORBIT_DOWN);
                        std::cout<<"SDLK_DOWN"<<std::endl;
                        break;
                    }
                    break;

                case SDL_MOUSEWHEEL:
                    if(event.wheel.y < 0)       // scroll up
                        m_viewerCamera->move(Camera::ZOOM_IN);
                    else if(event.wheel.y > 0)  // scroll down
                        m_viewerCamera->move(Camera::ZOOM_OUT);
                    break;
            }
        }


        glClearColor(.5f, 0.5f, 0.5f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_viewerCamera->update();
        Eigen::Matrix4f cameraVP = m_viewerCamera->m_projMat * m_viewerCamera->m_viewMat;

        for(auto & viewable : m_meshViewers)
            viewable->draw(cameraVP);

        for(auto & viewable : m_particleViewers)
            viewable->draw(cameraVP);

        SDL_GL_SwapWindow(m_window);
    }
}