#include "engine/engine.h"
#include <GLFW/glfw3.h>

int main() {
    Engine engine;

    while (engine.isRunning()) {
        engine.run();
    }
    
    engine.stop();
    return 0;
}
