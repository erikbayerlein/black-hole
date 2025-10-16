#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include <glm/glm.hpp>

using namespace glm;

class BlackHole {
    private:
        vec3 pos;
        double radius;
        double mass;
    
    public:
        double schwarzschild_radius;
        BlackHole(vec3 pos, float mass);
        void draw();
};

#endif
