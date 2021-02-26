#include <iostream>
#include <fstream>

using namespace std;

void poemHelper(int, string [], int);
//this function uses recursion calling itself to print out the body of the poem and stops when it reaches the end of the array.

void poemCantSleep(int, string[]);
//this function prints the initial and final lines and then calls the poemHelper function.

int main()
{
    string fileName, animalType[100], temp[100];
    ifstream file;
    cout << "Input animals filename: ";
    cin >> fileName;


    file.open(fileName.c_str());

     if(file.fail())
    {
        cout << "Unable to open "<< fileName << endl;
        file.close();
        return 1;
    }
    else
    {
        cout << endl;
        int i=0;
        while(!file.eof())
        {
            getline(file, animalType[i]);
            i++;
        }
        poemCantSleep(i-1, animalType);
        file.close();
    }
    return 0;
}

void poemHelper(int arrayNum, string animalNames[], int arrayLength)
{
    if(arrayNum==arrayLength-2)
    {
        cout << endl;
        for(int i=0; i<arrayNum+1; i++)
            cout << "\t";
        cout <<"who fell asleep." << endl;
    }
    else
    {
        arrayNum++;
        cout << endl;
        for(int i=0; i<arrayNum; i++)
            cout << "\t";
        cout << "Who couldn't sleep so the " << animalNames[arrayNum] << "'s mother told him a story about a little " << animalNames[arrayNum+1];
        poemHelper(arrayNum, animalNames, arrayLength);
        for(int i=0; i<arrayNum; i++)
            cout << "\t";
        cout << "And the " << animalNames[arrayNum] << " fell asleep." << endl;
    }
}

void poemCantSleep(int in, string animalName[])
{
    int j=0;
    cout << "There once was a little " << animalName[0];
    poemHelper(j-1, animalName, in);
    cout << "And her mother was happy.";
}
