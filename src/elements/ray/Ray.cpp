#include "ray.h"
#include <algorithm>
#include <cstddef>
#include <vector>

Ray::Ray(vec2 pos) : x(pos.x), y(pos.y) {}

void Ray::draw() const {
    glPointSize(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(2.0f);

    size_t N = trail.size();
    if (N >= 2) {
        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < N; ++i) {
            float alpha = float(i + 5) / float(N - 1);
            glColor4f(1.0f, 1.0f, 1.0f, std::max(alpha, 0.05f));
            glVertex2f(trail[i].x, trail[i].y);
        }
        glEnd();
    }

    glDisable(GL_BLEND);
}

void Ray::update() {
    x += 0.01f;
    trail.push_back(vec2(x, y));

    if (trail.size() > 400) {
        trail.erase(trail.begin());
    }
}
