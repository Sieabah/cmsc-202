//
// Created by Christopher on 9/5/2015.
//

#ifndef RAYTRACER_RENDERER_H
#define RAYTRACER_RENDERER_H

#include "Vector3D.h"
#include "Polygon.h"
#include <vector>

class Renderer {
public:
    //Default Constructor
    Renderer()
    : position(Vector3D()), lookAt(Vector3D()), upVector(Vector3D()),
    angle(0), hither(0), resX(640),resY(480){};

    //Vector constructor
    Renderer(Vector3D positionVec, Vector3D lookVec, Vector3D upVec, double iangle,
             double ihither, double iresX, double iresY)
    : position(positionVec), lookAt(lookVec), upVector(upVec), angle(iangle), hither(ihither),
      resY(resY), resX(iresX)
    {}

    //Manual constructor
    Renderer(double posX = 0.0, double posY = 0.0, double posZ = 0.0, double lookX = 0.0,
             double lookY = 0.0, double lookZ = 0.0, double upX = 0.0, double upY = 0.0,
             double upZ = 0.0, double iangle = 0.0, double ihither = 0.0,
             int iresX = 640, int iresY = 480)
    {
        position = Vector3D(posX, posY, posZ);
        lookAt  = Vector3D(lookX, lookY, lookZ);
        upVector = Vector3D(upX, upY, upZ);
        angle = iangle;
        hither = ihither;
        resX = iresX;
        resY = iresY;
    }

    void AddPoly(const Polygon &poly){ polygons.push_back(poly); }
private:
    Vector3D position;
    Vector3D lookAt;
    Vector3D upVector;
    double angle;
    double hither;
    int resX;
    int resY;

    std::vector<Polygon> polygons;
};


#endif //RAYTRACER_RENDERER_H
