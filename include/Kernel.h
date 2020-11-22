#ifndef KERNEL_H
#define KERNEL_H

// 
#include "Camera.h"
#include "MeshViewer.h"
#include "ParticleViewer.h"

// Window management
#include <GL/glew.h>
#include <SDL2/SDL.h>

class Kernel {
public:

    // Init kernel
    bool init(uint _windowWidth,
              uint _windowHeight,
              std::string const & _windowName);
    bool teardown();

    void run();

    bool loadScene(std::string const & scenePath);
    // Viewer camera
    std::unique_ptr<Camera> m_viewerCamera;

    // Viewers
    std::vector<MeshViewer<std::vector> *> m_meshViewers;
    std::vector<ParticleViewer<std::vector> *> m_particleViewers;

private:

    // SDL Window data
    uint m_windowWidth;
    uint m_windowHeight;
    std::string m_windowName;

    SDL_Window * m_window = nullptr;
    SDL_GLContext m_context = nullptr;

    bool m_isInitialized = false;
};

#endif /* KERNEL_H */