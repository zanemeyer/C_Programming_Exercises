#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//computes the distance between two points in (x,y) space
double distance(double fromX, double fromY, double toX, double toY);

//This function modifies the current point (currentX, currentY) to move it by a distance of stepSize towards the targetPoint (targetX, targetY)
void chase( double & currentX, double & currentY, double stepSize, double targetX, double targetY);

int main()
{
    double in1x,in1y,in2x,in2y,in3x,in3y,fin1x,fin1y,fin2x,fin2y,fin3x,fin3y,step;

    cout << "Initial point 1 (x y): ";
    cin >> in1x >> in1y;
    cout << "Initial point 2 (x y): ";
    cin >> in2x >> in2y;
    cout << "Initial point 3 (x y): ";
    cin >> in3x >> in3y;
    cout << "Step Size: ";
    cin >> step;

    while(1)
    {
        fin1x=in1x;
        fin1y=in1y;
        fin2x=in2x;
        fin2y=in2y;
        fin3x=in3x;
        fin3y=in3y;

        chase(in1x, in1y, step, fin2x, fin2y);
        chase(in2x, in2y, step, fin3x, fin3y);
        chase(in3x, in3y, step, fin1x, fin1y);

        cout<<fixed<<setprecision(3);
        cout<<setw(7)<<in1x<<" "<<setw(7)<<in1y<<" ";
        cout<<setw(7)<<in2x<<" "<<setw(7)<<in2y<<" ";
        cout<<setw(7)<<in3x<<" "<<setw(7)<<in3y<<endl;

        if((distance(in1x,in1y,in2x,in2y)+distance(in2x,in2y,in3x,in3y)+distance(in3x,in3y,in1x,in1y))<(3*step))
    break;
    }
    return 0;
}

void chase(double &currentX, double &currentY, double stepSize, double targetX, double targetY)
{

    double dx = ((targetX - currentX)*stepSize)/distance(targetX, targetY, currentX, currentY);
    double dy = ((targetY - currentY)*stepSize)/distance(targetX, targetY, currentX, currentY);

    currentX += dx;
    currentY += dy;
}

double distance(double fromX, double fromY, double toX, double toY)
{
    return sqrt(pow(toX - fromX, 2) +  pow(toY - fromY, 2) * 1.0);
}
