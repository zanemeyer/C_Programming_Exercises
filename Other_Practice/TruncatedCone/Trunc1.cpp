#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>
#include "TruncatedCone.hpp"

using namespace std;

int main()
{
    double baR[100], taR[100], ha[100];
    TruncatedCone tC[100];
    string fileName;
    ifstream file;
    cout << "enter cone file: ";
    cin >> fileName;


    file.open(fileName.c_str());

     if(file.fail())
    {
        cout << "unable to open "<< fileName << endl;
        file.close();
        return 1;
    }
    else
    {
        int i=0;
        while(file >> baR[i] >> taR[i] >> ha[i])
            i++;
        char areaVol;
        do
        {
            cout << "area or volume (a/v): ";
            cin >> areaVol;
        }while(areaVol!='a'&&areaVol!='v');

        if(areaVol=='a')
        {
            int a=0,bad[100];
            double area[100];
            bool sort0[100];

            for(int j=0; j<=i; j++)
            {
                tC[j].setAllSize(baR[j], taR[j], ha[j]);
                area[j]=tC[j].getSurfaceArea();

                if(j>0&&j<i&&area[j]<area[j-1])
                {

                        bad[a]=j;
                        sort0[j]=true;
                        a++;

                }
            }
            ofstream file0;
			file0.open("sortedCones.txt");
			int z=0;
            for(int c=0;c<i;c++)
            {

				if(sort0[c]==true&&c<i+3)
				{
					cout << "reject cone  " << bad[z] << endl;
					z++;
				}
				else
				{
					file0 << "Base Radius: " << tC[c].getBaseRadius() << ", Top Radius: " << tC[c].getTopRadius() << ", Height: " << tC[c].getHeight() << endl;
				}

			}
			file0.close();

		}
        else
        {
            int a=0,bad[100];
            double area[100];
            bool sort0[100];

            for(int j=0; j<=i; j++)
            {
                tC[j].setAllSize(baR[j], taR[j], ha[j]);
                area[j]=tC[j].getVolume();
               // cout << area[j] << " ";

                if(j>0&&j<i&&(area[j]<area[j-1]||area[j]<area[j-2]||area[j]<area[j-3]||area[j]<area[j-4]||area[j]<area[j-5]||area[j]<area[j-6]||area[j]<area[j-7]))
                {

                        bad[a]=j;
                        sort0[j]=true;
                        a++;

                }
            }
            ofstream file0;
			file0.open("sortedCones.txt");
			int z=0;
            for(int c=0;c<i;c++)
            {

				if(sort0[c]==true&&c<i+3)
				{
					cout << "reject cone  " << bad[z] << endl;
					z++;
				}
				else
				{
					file0 << "Base Radius: " << tC[c].getBaseRadius() << ", Top Radius: " << tC[c].getTopRadius() << ", Height: " << tC[c].getHeight() << endl;
				}

			}
			file0.close();

        }
        file.close();
    }
    return 0;
}
