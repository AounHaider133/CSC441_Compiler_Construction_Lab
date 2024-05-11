//Synopsis: Implement CFG: S-> aS | ^
#include<iostream>
using namespace std;

bool CFG(string input,int index=0)
{
    if(index == input.length())
     return true;
    if(input[index] == 'a')
     return CFG(input,index+1);
    else
     return false;
}
int main()
{
    string input;
    cout<<"Enter the string:";
    getline(cin,input);
    if(CFG(input))
     cout<<"Input Accepted!";
    else
     cout<<"Input Rejected";

    return 0;
}
