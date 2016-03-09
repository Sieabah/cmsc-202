//
// Created by Christopher on 9/5/2015.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H

#include <iostream>

class Vector3D {
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
    double x;
    double y;
    double z;

    Vector3D operator+(const Vector3D &other);
    Vector3D operator-(const Vector3D &other);
    Vector3D operator*(const double &other);
    Vector3D operator*(const int &other);

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
    {
        os << vec.x << ',' << vec.y << ',' << vec.z;
        return os;
    }
};

#endif //RAYTRACER_VECTOR3D_H
