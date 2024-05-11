//Lab Assignment 3
//Name: Mr.Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: CS-VF_Gul-Bano
//Bloom Taxonomy Level: <Applying>
//Synopsis: Remove left recursion from CFG having multiple beta rules and one left recursive rule in original grammer
//Lab Task: 9
#include<iostream>
#include <windows.h>
using namespace std;
void displayLeftRecursionRemoved(string grammer,char ruleName)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char alpha[40],beta[40],cfg[40];
    char newRule = ruleName;
    int alphaLength,betaLenth;
    int match[20];

    int totalLeftRecursiveRules = 0;
    int e = 3;
    cfg[0] = grammer[0];
    cfg[1] = '-';
    cfg[2] = '>';
    //Store positions of first element
    for(int i=0; i<grammer.length(); i++)
    {
        if((grammer[i]=='>'  ||grammer[i]=='|') && (grammer[0]==grammer[i+1])){
            match[totalLeftRecursiveRules] = i+1;
            totalLeftRecursiveRules++;
        }
    }
    int ialpha=0,ibeta=0;
    //Is first character is equal to rules character
    for(int l=0;l<totalLeftRecursiveRules;l++)
    {
        if(grammer[0] == grammer[match[l]])
        {
            int i;
            //Extracting all alphas
            for(i=match[l]+1;(grammer[i]!='|' && i < grammer.length());i++)
            {
              alpha[ialpha++] = grammer[i];
            }
            alpha[ialpha++] = '|';
            //Extracting all betas
            if(grammer[i+1] != grammer[0])
            {
                for(int x=i+1;((totalLeftRecursiveRules-1 == l)?(x<grammer.length()):(x<match[l]));x++)
                {
                    beta[ibeta++] = grammer[x];
                    //cout<<b[i]<<endl;
                }
            }
        }
    }
            //Extracting starting betas if exist before left recursive rule
            if(match[0] != 3)
            {
                if(ibeta != 0){
                beta[ibeta++] = '|';
                }
                for(int x=3;x<match[0]-1;x++)
                {
                    beta[ibeta++] = grammer[x];
                }
            }
            alpha[ialpha-1] = '\0';
            ialpha--;
            beta[ibeta] = '\0';

            //Inserting beta
            for(int i=0;i<ibeta;i++)
            {
                if(beta[i] == '|')
                {
                    cfg[e++] = newRule;
                    cfg[e++] = '|';
                }
                else{
                    cfg[e++] = beta[i];
                }
            }
            cfg[e++]=newRule;
            cfg[e++]='\n';
            cfg[e++] = newRule;
            cfg[e++] = '-';
            cfg[e++] = '>';

            //Inserting alphas
            for(int i=0;i<ialpha;i++)
            {
                if(alpha[i] == '|')
                {

                    cfg[e++] = newRule;
                    cfg[e++] = '|';
                }
                else{
                    cfg[e++] = alpha[i];
                }
            }

            cfg[e++]=newRule;
            cfg[e++] = '|';
            cfg[e++] = '^';
            cfg[e] = '\0';

            SetConsoleTextAttribute(hConsole, 2);
            cout<<cfg<<endl;
            SetConsoleTextAttribute(hConsole, 7);


}
int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string production1 = "S->a|b|Sc|d";
    string production2 = "A->Aa|s";
    string production3 = "B->b|Ba";

    cout<<"//CSC441 - Compiler Construction Lab 9"<<endl;
    cout<<"Original CFG:"<<endl;
    cout<<"-------------------------"<<endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout<<production1<<endl;
    cout<<production2<<endl;
    cout<<production3<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"-------------------------"<<endl;

    cout<<endl<<"After Removing Left Recursion:"<<endl;
    cout<<"-------------------------"<<endl;

    displayLeftRecursionRemoved(production1,'X');
    displayLeftRecursionRemoved(production2,'Y');
    displayLeftRecursionRemoved(production3,'Z');

    cout<<"-------------------------"<<endl;
}
