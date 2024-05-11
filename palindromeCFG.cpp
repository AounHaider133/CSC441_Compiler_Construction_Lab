//Synopsis: Implement CFG: S-> aSa | bSb | a | b | ^
//NOTE: use getline insted of cin>>input; to accept null string.
#include<iostream>
using namespace std;

bool match(int,int);
bool S(string,int=0);

int main()
{
    string input;
    cout<<"Enter the string:";
    getline(cin,input);

    if(S(input))
        cout<<"Input Accepted."<<endl;
    else
        cout<<"Input Rejected!"<<endl;

    return 0;
}
bool match(int index,int length)
{
    return index == length;
}
bool S(string input, int index)
{
    if (index >= input.length()) {
        return true;
    }

    if (input[index] == 'a' || input[index] == 'b') {
        return S(input, index + 1) && (input[index] == input[input.length() - index - 1]);
    }

    return false;
}
