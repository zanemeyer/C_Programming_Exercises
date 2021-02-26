#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "SystemUser.hpp"

using namespace std;

//prints out info regarding the other commands in the program that you can use.
void help();

int main()
{
    SystemUser accounts[10000];
    int i=0;
    string exitPar="empty";

    cout << "Welcome to USMASY the user management system" << endl;
    while(exitPar!="exit")
    {
        cout << "enter command: ";
        cin >> exitPar;
        if(exitPar=="help")
        {
            help();
        }
        else if(exitPar=="login")
        {
            string string1;
            cout << "username: ";
            cin >> string1;
            int j=0;
            while(j<i)
            {

                if(accounts[j].getUsername()==string1)
                    break;
                    j++;
            }
            if(accounts[j].getUsername()==string1)
            {
                string string2;
                cout << "password: ";
                cin >> string2;
                int z=0;
                while(z<2)
                {
                     if(!accounts[j].checkPassword(string2))
                     {
                         cout << "ERROR: incorrect password\n";
                         z++;
                         cout << "password: ";
                         cin >> string2;
                     }
                    else
                    {
                        cout << "login successful\n";
                        break;
                    }
                }
                    if(z==2){                        cout << "ERROR: incorrect password\n";
                        cout << "ERROR: login failed after 3 incorrect attempts\n";
                    }

            }
            else
            {
                cout << "ERROR: unable to find user data\n";
            }

        }
        else if(exitPar=="load")
        {
            if(i==0)
            {
                string fileName;
                ifstream file;
                cout << "enter a USMASY file name: ";
                cin >> fileName;

                file.open(fileName.c_str());

                 if(file.fail())
                {
                    cout << "unable to open "<< fileName << endl;
                    file.close();
                }
                else
                {
                    while(!file.eof())
                    {
                        file >> accounts[i];
                        i++;
                    }
                }
            }
            else
            {
                cout << "ERROR: user data already loaded." << endl;
            }

        }
        else if(exitPar=="exit")
        {
            cout << "Goodbye!\n";
            return 0;
        }
        else
        {
            cout << "ERROR: unknown command: " << exitPar << " type help for a command list" << endl;
        }
    }

}

void help()
{
    cout << "Welcome to USMASY the user management system" << endl << "The USMASY commands are: " << endl <<
    " * help\n" << " * load\n" << " * login\n" << " * exit\n";
}
