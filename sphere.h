//
// Created by Kira_ on 2022/7/12.
//

#ifndef SMALLPT_SPHERE_H
#define SMALLPT_SPHERE_H

#include "vec.h"
#include "ray.h"

enum class Refl_t { DIFF, SPEC, REFR };

struct Sphere
{
    double rad; // radius
    Point p;
    Vec e;
    Color c;
    Refl_t refl;

    Sphere(double rad_, Point p_, Vec e_, Color c_, Refl_t refl_)
        : rad(rad_), p(p_), e(e_), c(c_), refl(refl_) {}

    // test whether hit, return distance, 0 if not hit
    double intersect(const Ray& r) const
    {
        Vec op = p - r.o;
        double t, eps = 1e-4;
        Vec dir = r.d;
        double a = dir.dot(dir);
        double b = 2.0 * op.dot(r.d);
        double c_ = op.dot(op) - rad * rad;
        double half_b = b / 2.0;
        double det = half_b * half_b - a * c_;
        if (det < 0) return 0;
        else det = sqrt(det);

        // return smaller positive t
        t = (half_b - det) / a;
        if (t > eps) return t;
        else
        {
            t = half_b + det;
            if (t > eps) return t;
            else return 0;
        }
    }

};

#endif //SMALLPT_SPHERE_H
