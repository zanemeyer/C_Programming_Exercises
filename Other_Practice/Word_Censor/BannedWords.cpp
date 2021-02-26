#include <iostream>
#include <fstream>

using namespace std;

//removes all the banned lines from the text inputted at the start
string bannedRemover(string[1000],string[100],int);
//counts how many characters are in a string
int stringCount(string);

int main()
{
    string fileName,banWrds[100],badWrds[100],wrds[1000];
    int i=0,j=0,k=0;
    ifstream file,file2,file3;

    file2.open("BannedWords.txt");
        while(file2 >> banWrds[i])
        {
            i++;
        }
    file2.close();

    file3.open("BadWords.txt");
        while(file3 >> badWrds[j])
        {
            j++;
        }
    file2.close();

    cout << "input text file to cleanup: ";
    cin >> fileName;
	cout << endl;
    file.open(fileName.c_str());

     if(file.fail())
    {
        cout << "file read error" << endl;
        file.close();
        return 1;
    }
    else
    {
        while(true)
        {
            if( file.eof() ) break;
            getline(file, wrds[k]);
            k++;
        }
        file.close();
        string strBan;

        strBan=bannedRemover(wrds,banWrds,k);
        int hg=0;
        while(hg<12)
        {
            while (strBan.find(badWrds[hg]) != string::npos)
                strBan.replace(strBan.find(badWrds[hg]), stringCount(badWrds[hg]), string(stringCount(badWrds[hg]),'*'));
            hg++;
        }
        strBan.erase(strBan.length()-2);
        cout << strBan;
    }


    return 0;
}

string bannedRemover(string temp[1000], string temp2[100],int i)
{
    int a=0;
    string strR;
    bool test=false;
    while(a<i)
    {
        int z=0;
        while(z<7)
        {
            if(!((temp[a].find(temp2[z])==-1)))
            {

                test=true;
            }
            z++;
        }
        if(test==false)
        {
            strR+=temp[a];
            strR+="\n";
        }
        test=false;
        a++;
    }
    return strR;
}

int stringCount(string str)
{
    int i=str.length();
    return i;
}
