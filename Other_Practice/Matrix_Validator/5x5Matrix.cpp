#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//checks if the diagonals have duplicates
bool checkMatx1(int[5][5]);
//checks if there are zeros inside of the diagonals
bool checkMatx2(int[5][5]);
//checks if there are non-zeros outside of the diagonals
bool checkMatx3(int[5][5]);
//outputs the matrix using loops
void coutMatrix(int[5][5]);

int main()
{
    string fileName;
    bool dups, zeroIn,nonZeroOut;
    ifstream file;
    cout << "Input filename containing the 5x5 matrix: ";
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
        int matx[5][5],i=0,j=0;

            for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    file >> matx[i][j];
                }
            }
            cout << endl;
        file.close();

        coutMatrix(matx);
        dups=checkMatx1(matx);
        zeroIn=checkMatx2(matx);
        nonZeroOut=checkMatx3(matx);

        if(dups==false&&zeroIn==false&&nonZeroOut==false)
        {
            cout << "Matrix successfully validated!";
        }

    }
    return 0;
}

bool checkMatx1(int temp[5][5])
{
    bool buel=false;
    int chk;

    for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    chk=temp[i][j];
                    for(int a=i;a<5;a++)
                    {
                        for(int b=0;b<5;b++)
                        {
                            if(a!=i&&b!=j)
                            {
                               if(chk==temp[a][b] && chk!=0)
                               {
                                   cout<<"Matrix contains non unique elements!"<< endl << "Unable to validate matrix";;
                                   buel=true;
                                   break;
                                   //break statement so it doesn't execute the rest of the loop
                               }
                            }
                        }
                    }
                }
            }
    return buel;
}
bool checkMatx2(int temp[5][5])
{
     bool buel=false;
     int chk;

     for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    chk=temp[i][j];
                    if(i+j!=4&&i!=j)
                    {
                        if(chk!=0)
                        {
                            cout << i <<","<< j << "th element is nonzero!" << endl << "Unable to validate matrix";
                            buel=true;
                            break;
                            //break statement so it doesn't execute the rest of the loop
                        }
                    }
                }
            }
    return buel;
}
bool checkMatx3(int temp[5][5])
{
    bool buel=false;
    int chk;

    for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    chk=temp[i][j];
                    if(i+j==4||i==j)
                    {
                        if(chk==0)
                        {
                            cout << i <<","<< j << "th Diagonal element is zero!" << endl << "Unable to validate matrix";
                            buel=true;
                            break;
                            //break statement so it doesn't execute the rest of the loop
                        }
                    }
                }
            }
    return buel;
}
void coutMatrix(int temp[5][5])
{
    for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    cout << setw(3) << temp[i][j];
                }
                cout << endl;
            }
            cout << endl;
}
