#include <iostream>

using namespace std;
//fills the array with the wanted numbers
void fillArray(int [], int size);

//draws the correct histogram using for loops
void draw(int[], int, int);

//tests to see if the wanted numbers are negative or not
bool negativeTest(int [], int);

//finds the maximum value in the array
int maxVal(int[], int);

int main()
{
    const int s=20;
    int a[s];

    fillArray(a, s);

    return 0;
}

void fillArray(int array[], int size)
{
    bool plac;
    do
    {
    cout << "Enter 20 positive numbers to create a histogram: ";
    for(int i=0; i<size; i++)
    {
        cin >> array[i];
    }
    plac=negativeTest(array, size);
    }
    while(plac==false);
    draw(array, size, maxVal(array, size));
}

void draw(int array[], int ins, int maxV)
{
            for(int i=maxV;i>=1;i--)
            {
                for(int j=0;j<ins;j++)
                {
                    if(array[j]==i)
                    {
                        cout<<"#";
                        array[j]--;
                    }
                    else
                        cout<<".";
                        cout<<" ";
                }
                    cout<<endl;
            }
}

bool negativeTest(int nums[],int maxNums)
{
    for(int i=0; i<maxNums; i++)
        {
            if(nums[i]<0)
            {
                return false;
            }
        }
    return true;
}

int maxVal(int nums[],int num)
{
    int maxNum=0;
    for(int i=0; i<num; i++)
        {
            if(nums[i]>maxNum)
            {
                maxNum=nums[i];
            }
        }
    return maxNum;
}
