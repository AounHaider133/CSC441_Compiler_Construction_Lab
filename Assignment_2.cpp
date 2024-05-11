//Create a language which accepts string 'aabaa'
//Lab Assignment 2
//Name: Mr.Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: CS-VF_Gul-Bano
#include<iostream>
using namespace std;

int main()
{
    string str = "aabaa";
    char state = 'S';
    string msg = "String not parsed properly!";

    cout<<"Test string: "<<str<<endl<<"Matched: ";
    for(int i=0;i<=str.length();i++)
    {
        switch(state)
        {
        case 'S':
            if(str[i] == 'a')
            {
                cout<<str[i];
                state = 'A';
            }
            else
             state = 'F';
            break;
        case 'A':
            if(str[i] == 'a')
            {
                cout<<str[i];
                state = 'B';
            }
            else
             state = 'F';
            break;
        case 'B':
            if(str[i] == 'b')
            {
                cout<<str[i];
                state = 'C';
            }
            else
             state = 'F';
            break;
        case 'C':
            if(str[i] == 'a')
            {
                cout<<str[i];
                state = 'D';
            }
            else
             state = 'F';
            break;
        case 'D':
            if(str[i] == 'a')
            {
                cout<<str[i];
                state = 'E';
            }
            else
             state = 'F';
            break;
        case 'E':
            msg = "String Found!";
            break;
        case 'F':
            msg = "Dead End!";
            break;
        }
    }
    cout<<endl<<"Outcome: "<<msg<<endl;
}
