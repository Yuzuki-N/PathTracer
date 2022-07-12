#include "sphere.h"

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

inline double clamp(double x) { return x < 0 ? 0 : x > 1 ? 1 : x; }

// conver float to int and gamma corrct
inline int toInt(double x) { return int(lround(pow(clamp(x), 1 / 2.2) * 255 + 0.5));}

// intersects with whole scene
inline bool intersect_with_scene(const Ray& r, double& t, int& id, Sphere spheres[], int n)
{
    double d;
    double inf = t = 1e20;

    for (int i = n; i >= 0; i--)
    {
        if ((d = spheres[i].intersect(r)) && d < t)
        {
            // t是光线初始点到球的距离
            t = d;
            id = i;
        }
    }
    return t < inf;
}


double erand48(unsigned short xsubi[3])
{
    return double(rand()) / double(RAND_MAX);
}

int main() {
    Sphere spheres[] = {
            Sphere{1e5, Point{1e5 + 1, 40.8, 81.6}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Left
            Sphere{1e5, Point{-1e5 + 1, 40.8, 81.6}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Right
            Sphere{1e5, Point{50, 40.8, 1e5}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Back
            Sphere{1e5, Point{50, 40.8, -1e5+170}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Frnt
            Sphere{1e5, Point{50, 1e5, 81.6}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Botom
            Sphere{1e5, Point{50 + 1, -1e5+81.6, 81.6}, Vec{}, Color{.75, .25, .25}, Refl_t::DIFF}, // Top
            Sphere{16.5, Point{27, 16.5, 47}, Vec{}, Color{.75, .25, .25}, Refl_t::SPEC}, // Mirr
            Sphere{16.5, Point{73, 16.5, 78}, Vec{}, Color{.75, .25, .25}, Refl_t::REFR}, // Glas
            Sphere{1.5, Point{50, 81.6-16.5, 81.6}, Vec{4, 4, 4}*100, Color{}, Refl_t::DIFF}, // Lite
    };

    int numSpheres = sizeof(spheres) / sizeof(Sphere);
    return 0;
}
