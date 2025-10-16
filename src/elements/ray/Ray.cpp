#include "ray.h"
#include "../../geodesic/geodesic.h"
#include <algorithm>
#include <cstddef>
#include <vector>

Ray::Ray(vec2 pos, vec2 dir, BlackHole bh) : x(pos.x), y(pos.y), r(sqrt(pos.x * pos.x + pos.y * pos.y)), phi(atan2(pos.y, pos.x)), dr(dir.x), dphi(dir.y) {
    // step 1) get polar coords (r, phi) :
    this->r = sqrt(x*x + y*y);
    this->phi = atan2(y, x);
    // step 2) seed velocities :
    dr = dir.x * cos(phi) + dir.y * sin(phi); // m/s
    dphi  = ( -dir.x * sin(phi) + dir.y * cos(phi) ) / r;
    // step 3) store conserved quantities
    L = r*r * dphi;
    double f = 1.0 - bh.schwarzschild_radius/r;  
    double dt_dλ = sqrt( (dr*dr)/(f*f) + (r*r*dphi*dphi)/f );
    E = f * dt_dλ;
    // step 4) start trail :
    trail.push_back({x, y});
}

void Ray::draw(const std::vector<Ray>& rays) {
    // draw current ray positions as points
    glPointSize(2.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for (const auto& ray : rays) {
        glVertex2f(ray.x, ray.y);
    }
    glEnd();

    // turn on blending for the trails
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1.0f);

    // draw each trail with fading alpha
    for (const auto& ray : rays) {
        size_t N = ray.trail.size();
        if (N < 2) continue;

        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < N; ++i) {
            // older points (i=0) get alpha≈0, newer get alpha≈1
            float alpha = float(i) / float(N - 1);
            glColor4f(1.0f, 1.0f, 1.0f, std::max(alpha, 0.05f));
            glVertex2f(ray.trail[i].x, ray.trail[i].y);
        }
        glEnd();
    }

    glDisable(GL_BLEND);
}

void Ray::step(double dλ, double rs) {
    // 1) integrate (r,φ,dr,dφ)
    if(r <= rs) return; // stop if inside the event horizon
    rk4Step(*this, dλ, rs);

    // 2) convert back to cartesian x,y
    x = r * cos(phi);
    y = r * sin(phi);

    // 3) record the trail
    trail.push_back({ float(x), float(y) });
}
