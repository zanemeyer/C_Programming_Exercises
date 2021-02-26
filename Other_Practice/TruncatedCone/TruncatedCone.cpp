#include "TruncatedCone.hpp"

TruncatedCone::TruncatedCone()
{
    baseRadius=2;
    topRadius=1;
    height=3;
}
TruncatedCone::TruncatedCone(double bR, double tR, double h)
{
    baseRadius=bR;
    topRadius=tR;
    height=h;
}
void TruncatedCone::setAllSize(double bR, double tR, double h)
{
    baseRadius=bR;
    topRadius=tR;
    height=h;
}
double TruncatedCone::getVolume()
{
    return ((pow(baseRadius, 2.0))+(baseRadius*topRadius)+(pow(topRadius, 2.0)))*height*M_PI*(1.0/3.0);
}
double TruncatedCone::getLateralArea()
{
    return M_PI*(baseRadius+topRadius)*sqrt(pow((baseRadius-topRadius), 2.0)+pow(height, 2.0));
}
double TruncatedCone::getSurfaceArea()
{
    return (M_PI*(baseRadius+topRadius)*sqrt(pow((baseRadius-topRadius), 2.0)+pow(height, 2.0)))+(M_PI*((pow(baseRadius, 2.0)+pow(topRadius, 2.0))));
}
double TruncatedCone::getBaseRadius() const
{
    return baseRadius;
}
double TruncatedCone::getTopRadius() const
{
    return topRadius;
}
double TruncatedCone::getHeight() const
{
    return height;
}
void TruncatedCone::printAllSize(ostream& out)
{
    out << "Volume: " << getVolume() << endl;
    out << "Lateral Area: " << getLateralArea() << endl;
    out << "Surface Area: " << getSurfaceArea() << endl;
}
void TruncatedCone::printAllCalculations(ostream& out)
{
    out << "Base Radius: " << baseRadius << ", Top Radius: " << topRadius << ", Height: " << height << endl;
}
