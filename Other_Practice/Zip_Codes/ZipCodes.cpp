#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int population, zip_code, div, ageDif, sum=0;
    double  minimum_age, maximum_age, sum2=0.0, sum3=0.0;
    ifstream outputStream;
    string dataName;
    cout << "input your full filename: ";
    getline( cin, dataName );
    cout << "input your divisor for zipcodes: ";
    cin >> div;
    cout << "input your age difference limit: ";
    cin >> ageDif;
    outputStream.open( dataName.c_str() );

    if
		(outputStream.fail())
		{
			cout << "Unable to open"<< dataName << endl;
			return 1;
		}
    else
		{
            while(outputStream >> population >> minimum_age >> maximum_age >> zip_code)
            {
                if(zip_code%div==0)
                {
                    sum+=population;
                }
                if((maximum_age-minimum_age)<ageDif)
                {
                    sum2++;
                    sum3+=population;

                }
            }
		}
		outputStream.close();
		cout << "zipcode sum with given divisor is " << sum << endl;
		cout << "average population within the age difference limit " << sum3/sum2 << endl;
    return 0;
}
