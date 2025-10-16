#include "black_hole.h"
#include <GLFW/glfw3.h>

const double G = 6.67430e-11;
const double c = 299792458.0;
const double WORLD_SCALE = 1.3e11;

BlackHole::BlackHole(vec3 pos, float mass) : pos(pos), mass(mass) {
    schwarzschild_radius = 2.0 * G * mass / (c*c);
}

void BlackHole::draw() {
    const float R = static_cast<float>(schwarzschild_radius / WORLD_SCALE); // world units
    const float cx = static_cast<float>(pos.x / WORLD_SCALE);
    const float cy = static_cast<float>(pos.y / WORLD_SCALE);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,0,0);
    glVertex2f(cx, cy);
    for (int i=0; i<=100; ++i) {
        float a = 2.0f * M_PI * i / 100;
        glVertex2f(cx + R * cosf(a), cy + R * sinf(a));
    }
    glEnd();
}
