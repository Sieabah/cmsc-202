//
// Created by Christopher on 9/5/2015.
//

#include "Vector3D.h"

Vector3D::Vector3D(double ix, double iy , double iz)
    : x(ix), y(iy), z(iz) {}

Vector3D Vector3D::operator+(const Vector3D &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3D Vector3D::operator*(const double &other)
{
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

Vector3D Vector3D::operator*(const int &other)
{
    x *= other;
    y *= other;
    z *= other;
    return *this;
}
