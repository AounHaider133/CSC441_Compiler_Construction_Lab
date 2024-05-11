//Lab Assignment 1
//Name: Mr. Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: Muhammad Bilal Arshad

//Implement soft-coded (transition table) based program to extract comments
#include<iostream>
#include<fstream>
#define BUFF_SIZE 4096
using namespace std;

enum COL{
    SLASH=0,STAR,OTHER,A,R,T
};
COL getColType(char ch)
{
    if(ch == '/') return SLASH;
    else if(ch == '*') return STAR;
    return OTHER;
}
int main()
{
    enum TOK{
      N=0,COM,ID,KEY,PUN,OP,LIT
    };

    char buff1[BUFF_SIZE];
    char buff2[BUFF_SIZE];
    string str;
    int i,j1=0,j2=0;
    ifstream codeFile("double_buffer.cpp");

    char c;
    while(codeFile.get(c))
    {
      if(j1 < BUFF_SIZE){
        buff1[j1] = c;
        j1++;
      }
      else if(j2 < BUFF_SIZE){
        buff2[j2] = c;
        j2++;
      }
    }

    char buff[4096] = "/*Welcome to *CC-Lab-5!*/ \nprice = x*y;\0";
    char lex[100];

    int Transition_Table[5][6] = {
    {1,-1,-1,false,false,N},
    {-1,2,-1,false,false,N},
    {-1,3,2,false,false,N},
    {4,3,2,false,false,N},
    {-1,-1,-1,true,true,COM},
    };
    int bi=0,li=0,state=0;
    char ch;
    int numOfValidInputs = 2;
    bool inComment = false;


    while((ch=buff1[bi])!='\0')
    {
        if(Transition_Table[state][A] != true)
        {
            int previous_state = state;
            state = Transition_Table[state][getColType(ch)];

            if(state == 2 && previous_state != 1){
            lex[li] = ch;
            li++;
            }
            else if(state == -1)
            {
                break;
            }
        }

        else if(li>0)
        {
            lex[li] = '\0';
            li = 0;
            if(Transition_Table[state][R]){
              bi--;
            }
            cout<<"Comment: "<<lex<<endl;
            state = 0;
        }
        bi++;
    }
}
