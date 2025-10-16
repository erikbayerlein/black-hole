#include "engine.h"
#include <iostream>

Engine::Engine() {
    configs();

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(WIDTH, HEIGHT, "Black Hole 2D Simulator", nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    int fbw, fbh;
    glfwGetFramebufferSize(window, &fbw, &fbh);
    glViewport(0, 0, fbw, fbh);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* w, int wpx, int hpx) {
        glViewport(0, 0, wpx, hpx);
    });

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Engine::run() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int fbw, fbh; glfwGetFramebufferSize(window, &fbw, &fbh);
    double aspect = (double)fbw / (double)fbh;
    glOrtho(-aspect, aspect, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Engine::stop() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}

bool Engine::isRunning() const {
    return window && !glfwWindowShouldClose(window);
}

void Engine::configs() {
#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
}
