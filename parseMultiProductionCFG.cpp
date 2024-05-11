//Synopsis: Implement CFG: S-> aA | ^, A -> bA | ^
//NOTE: use getline insted of cin>>input; to accept null string.
#include<iostream>
using namespace std;

bool match(int,int);
bool A(string,int);
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
bool S(string input,int index)
{
    if(input[index] == 'a')
        return A(input,index+1);
    else
        return match(index,input.length());
}
bool A(string input,int index)
{
    if(input[index] == 'b')
        return A(input,index+1);
    else
        return match(index,input.length());
}

