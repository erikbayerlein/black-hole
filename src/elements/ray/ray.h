#ifndef RAY_H
#define RAY_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace glm;

class Ray {
private:
    double x;
    double y;

    vector<vec2> trail;

public:
    Ray(vec2 pos);
    void draw() const;
    void update();
};

#endif
