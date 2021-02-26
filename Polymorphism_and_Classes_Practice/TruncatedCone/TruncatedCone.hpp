#include <iostream>
#include <cmath>
#include <math.h>
# ifndef TRUNCATEDCONE_HPP
# define TRUNCATEDCONE_HPP

using namespace std;

//This class holds all the information important for truncated cones
class TruncatedCone
{
    public:
    double baseRadius, topRadius, height;
    TruncatedCone();
    TruncatedCone(double bR, double tR, double h);
    void setAllSize(double bR, double tR, double h);
    double getVolume();
    double getLateralArea();
    double getSurfaceArea();
    double getBaseRadius() const;
    double getTopRadius() const;
    double getHeight() const;

    void printAllSize(ostream& out);
    void printAllCalculations(ostream& out);

};

#endif
