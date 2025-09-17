#include "elements/black_hole/black_hole.h"
#include "elements/ray/ray.h"
#include "engine/engine.h"
#include <GLFW/glfw3.h>

int main() {
    Engine engine;
    vector<Ray> rays;
    BlackHole black_hole(vec3(0.0f, 0.0f, 0.0f), 8.54e36);

    rays.push_back(Ray(vec2(-1.0f, 0.0f)));

    while (engine.isRunning()) {
        engine.run();

        black_hole.draw();

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
