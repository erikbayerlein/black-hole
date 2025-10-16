#ifndef RAY_H
#define RAY_H

#include "../black_hole/black_hole.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace glm;

class Ray {
private:

public:
    // cartesian coord
    double x;
    double y;

    // polar coords
    double r;   double phi;
    double dr;  double dphi;

    double E, L;

    vector<vec2> trail;

    Ray(vec2 pos, vec2 dir, BlackHole bh);
    void draw(const std::vector<Ray>& rays);
    void step(double dλ, double rs);
};

#endif
