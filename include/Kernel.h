#ifndef KERNEL_H
#define KERNEL_H

// Window management
#include <GL/glew.h>
#include <SDL2/SDL.h>

class Kernel {
public:
    static Kernel& get() {
    	static Kernel instance;
        return instance;
    }

    // 
    bool init();

    // Viewer camera
    Camera m_viewerCamera;

    // Viewers
    std::vector<MeshViewer *> m_meshViewers;
    std::vector<ParticleViewer *> m_particleViewers;

private:

    Kernel() = default;

    // SDL Window data
    uint m_windowWidth;
    uint m_windowHeight;
    std::string m_windowName;

    SDL_Window * m_window = nullptr;
    SDL_GLContext * m_context = nullptr;

};

#endif /* KERNEL_H */