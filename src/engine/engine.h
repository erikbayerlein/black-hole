#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include <cstdlib>

class Engine {
private:
    GLFWwindow* window;
    const int WIDTH = 800;
    const int HEIGHT = 600;

    void configs();

public:
    Engine();
    void run();
    void stop();
    bool isRunning() const;
};

#endif
