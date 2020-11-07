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
                                    windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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
    glDepthFunc(GL_LESS);

    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(m_window && m_context)
        SDL_GL_SwapWindow(m_window);

    m_isInitialized = true;
    return true;
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