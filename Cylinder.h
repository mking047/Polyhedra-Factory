#ifndef CYLINDER_H_INCLUDED
#define CYLINDER_H_INCLUDED

#include "Polyhedron.h"

class Cylinder : public Polyhedron {
    private:
        double height;
        double radius;

    public:
        /**
         * Default Constructor
         */
        Cylinder();

        /**
         * Construct a cylinder with
         * specified height and radius
         */
        Cylinder(double r, double h);

        /**
         * Destructor
         */
        Cylinder(const Cylinder& src);

        ~Cylinder();
        double getDiameter() const;
        virtual void read(std::istream& ins);
        virtual Polyhedron* clone() const;
        virtual void scale(double scalingFactor);
        virtual void display(std::ostream& outs) const;

};

inline
Polyhedron* Cylinder::clone() const
{
    return new Cylinder(this->radius, this->height);
}

inline
double Cylinder::getDiameter() const
{
    return (2 * radius);
}

#endif
