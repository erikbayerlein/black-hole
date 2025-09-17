#include "black_hole.h"
#include <GLFW/glfw3.h>

const double G = 6.67430e-11;
const double c = 299792458.0;
const double WORLD_SCALE = 1.3e11;

BlackHole::BlackHole(vec3 pos, float mass) : pos(pos), mass(mass) {
    schwarzschild_radius = 2.0 * G * mass / (c*c);
}

void BlackHole::draw() {
    const float Rw = static_cast<float>(schwarzschild_radius / WORLD_SCALE);
    const float xw = static_cast<float>(pos.x / WORLD_SCALE);
    const float yw = static_cast<float>(pos.y / WORLD_SCALE);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw, yw);
    for(int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * i / 100;
        float x = xw + Rw * cosf(angle);
        float y = yw + Rw * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

