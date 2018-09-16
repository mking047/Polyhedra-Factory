#include "Polyhedron.h"
#include "Composite.h"

/**
 *
 */
Composite::Composite()
    :Polyhedron("Composite"),
     numPolyhedra(0),
     polyhedra(nullptr)
{
}

//------------------------HINT------------------------
/**
 *
 */
void Composite::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << numPolyhedra << " polyhedra" << "\n";

    for (int i = 0; i < numPolyhedra; i++) {
        //polyhedra[i]->display(outs);
        outs << "  " << (*polyhedra[i]) << "\n";
    }
}


//
/**
 *
 */
Composite& Composite::operator=(Composite rhs)
{
    swap(*this, rhs);

    return *this;
}

/**
 *
 */
void swap(Composite& lhs, Composite& rhs)
{
    using std::swap;

    std::swap(lhs.numPolyhedra, rhs.numPolyhedra);
    std::swap(lhs.polyhedra, rhs.polyhedra);

    // Friend functions allow direct access
    // to all data members.
    // This is well known 3-line
    // swap code
    BoundingBox temp = lhs.boundingBox;
    lhs.boundingBox  = rhs.boundingBox;
    rhs.boundingBox  = temp;
}

void Composite::read(std::istream& ins)
{
    ins >> numPolyhedra;

    polyhedra = new Polyhedron*[numPolyhedra];

    for(int i = 0; i < numPolyhedra; i++)
    {
        ins >> polyhedra[i];
        boundingBox.merge(polyhedra[i]->getBoundingBox());
    }

}

Composite::Composite(const Composite& src)
  :Polyhedron("Composite"),
   numPolyhedra(0),
   polyhedra(nullptr)
{
    numPolyhedra = src.numPolyhedra;
    polyhedra = new Polyhedron*[numPolyhedra];

    for(int i = 0; i < numPolyhedra; i++)
    {
        polyhedra[i] = src.polyhedra[i]->clone();
        boundingBox.merge(polyhedra[i]->getBoundingBox());
    }
}

void Composite::scale(double scalingFactor)
{
    for(int i = 0; i < numPolyhedra; i++)
    {
        polyhedra[i]->scale(scalingFactor);
    }

    boundingBox.scale(scalingFactor);

}

Composite::~Composite()
{
    delete polyhedra;

}

