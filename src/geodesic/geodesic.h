#pragma once
#include "../elements/ray/ray.h"

void geodesicRHS(const Ray& ray, double rhs[4], double rs);
void addState(const double a[4], const double b[4], double factor, double out[4]);
void rk4Step(Ray& ray, double dλ, double rs);
