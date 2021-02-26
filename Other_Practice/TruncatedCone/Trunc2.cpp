#include <iostream>
#include <cmath>
#include <math.h>
#include "TruncatedCone.hpp"

using namespace std;

int main()
{
    double baR, taR, ha;

    TruncatedCone c1;
    c1.printAllCalculations(cout);
    c1.printAllSize(cout);
    cout << "Input base radius, top radius, and height of the truncated cone: ";
    cin >> baR >> taR >> ha;
    c1.setAllSize(baR, taR, ha);
    c1.printAllCalculations(cout);
    c1.printAllSize(cout);
    cout << "Input base radius, top radius, and height of the truncated cone: ";
    cin >> baR >> taR >> ha;
    c1.setAllSize(baR, taR, ha);
    c1.printAllCalculations(cout);
    c1.printAllSize(cout);

    return 0;
}
