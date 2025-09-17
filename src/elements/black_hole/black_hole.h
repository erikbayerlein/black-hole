#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include <glm/glm.hpp>

using namespace glm;

class BlackHole {
    private:
        vec3 pos;
        double radius;
        double mass;
        double schwarzschild_radius;
    
    public:
        BlackHole(vec3 pos, float mass);
        void draw();
};

#endif
