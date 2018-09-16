#include "Cylinder.h"

/**
 *
 */
Cylinder::Cylinder()
    :Polyhedron("Cylinder"),
     height(0),
     radius(0)
{
}

//------------------------HINT------------------------
/**
 *
 */
Cylinder::Cylinder(double r, double h)
    :Polyhedron("Cylinder"),
     radius(r),
     height(h)
{
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

/**
 *
 */
Cylinder::~Cylinder()
{
}

void Cylinder::read(std::istream& ins)
{
    ins >> height; //get height from istream
    ins >> radius; //get radius from istream

    double d = this->getDiameter();

    boundingBox.setUpperRightVertex(d, d, height);
}

void Cylinder::scale(double scalingFactor)
{
    radius = radius * scalingFactor;
    height = height * scalingFactor;
    boundingBox.scale(scalingFactor);
}

void Cylinder::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << "Radius: " <<radius<<" Height: " << height;
}


Cylinder::Cylinder(const Cylinder& src)
  :Polyhedron("Cylinder"),
   height(0),
   radius(0)
{
    this->height = src.height;
    this->radius = src.radius;
}



