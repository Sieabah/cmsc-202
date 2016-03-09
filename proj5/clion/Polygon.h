//
// Created by Christopher on 9/5/2015.
//

#ifndef RAYTRACER_POLYGON_H
#define RAYTRACER_POLYGON_H

#include <vector>

class Polygon {
public:
    Polygon(int count, double verts[])
    {
        for (int i = 0; i < count; ++i) {
            vertices.push_back(verts[i]);
        }
    }

private:
    std::vector<double> vertices;
};


#endif //RAYTRACER_POLYGON_H
