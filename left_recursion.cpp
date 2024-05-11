#include<iostream>
using namespace std;

int main()
{
    string alpha,beta;
    string grammer = "S->Sa|b";
    int match;
    bool rec = false;
    for(int i=0; i<grammer.length(); i++)
    {
        if(grammer[i]=='>')
            match = i+1;
    }
    //Is first character is equal to rules character
    if(grammer[0] == grammer[match])
    {
        rec = true;

    }

}
