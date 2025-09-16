#include "elements/ray/ray.h"
#include "engine/engine.h"
#include <GLFW/glfw3.h>

int main() {
    Engine engine;
    vector<Ray> rays;

    rays.push_back(Ray(vec2(-1.0f, 0.0f)));

    while (engine.isRunning()) {
        engine.run();

        for (auto& ray : rays) {
            ray.update();
            ray.draw();
        }

        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }
    
    engine.stop();
    return 0;
}
