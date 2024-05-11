//Bloom Taxonomy Level: <Applying>
//Synopsis: Remove left recursion from CFG having one beta rule and one left recursive rule in original grammer
//Lab Task: 8
#include<iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char alpha[40],beta[40];
    int alphaLength,betaLenth;
    string grammer = "S->Sa|b";
    int match;
    bool rec = false;

    cout<<"//CSC441 - Compiler Construction Lab 8"<<endl;
    cout<<"Original CFG:"<<endl;
    cout<<"-------------------------"<<endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout<<grammer<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"-------------------------"<<endl;

    for(int i=0; i<grammer.length(); i++)
    {
        if(grammer[i]=='>')
            match = i+1;
    }
    int x = 0;
    //Is first character is equal to rules character
    if(grammer[0] == grammer[match])
    {

        int y = 0,i;
        //Extracting alpha
        for(i=match+1; grammer[i] != '|'; i++)
        {
            alpha[x] = (char)grammer[i];
            x++;
        }
        alpha[x] = '\0';
        alphaLength = x;
        x = 0;
        //Extracting beta
        for(i=i+1; i<grammer.length(); i++)
        {
            beta[x] = (char)grammer[i];
            x++;
        }
        betaLenth = x;
        beta[x] = '\0';

        char cfg[40];
        int e = 3;
        cfg[0] = grammer[0];
        cfg[1] = '-';
        cfg[2] = '>';

        //Insert beta
        for(int i=0;i<betaLenth;i++)
        {
            cfg[e] = beta[i];
            e++;
        }

        char newRule = 'X';
        cfg[e++] = newRule;
        cfg[e++] = '\n';
        cfg[e++] = newRule;
        cfg[e++] = '-';
        cfg[e++] = '>';

        //Insert alpha
        for(int i=0;i<alphaLength;i++)
        {
            cfg[e] = alpha[i];
            e++;
        }
        cfg[e++] = newRule;
        cfg[e++] = '|';
        cfg[e++] = '^';
        cfg[e] = '\0';

        cout<<endl<<"After Removing Left Recursion:"<<endl;
        cout<<"-------------------------"<<endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout<<cfg<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"-------------------------"<<endl;

    }

  /*for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
  }*/

}
