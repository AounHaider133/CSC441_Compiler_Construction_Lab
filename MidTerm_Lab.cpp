#include<iostream>
#include<fstream>
using namespace std;
#define BUFF_SIZE 4096

enum COL{
    DQ=0,S,O,A,R,T
};
enum TOK{
      N=0,STRING
};
int TT[4][6] = {
      {1,-1,-1,false,false,N},
      {3,2,1,false,false,N},
      {1,-1,-1,false,false,N},
      {0,0,0,true,true,STRING}
};
COL getColType(char ch)
{
    if(ch == '"') return DQ;
    else if(ch == '\\') return S;
    return O;
}
void IdentifyStringLiterals(char buff[])
{
    //Identify string literals
    char lex[4000];

    int bi=0,li=0,state=0;
    char ch;
    int numOfColumns = 2;
    int symbolTableID=0;
    bool insideString = false; // Flag to indicate if we're inside a string

    while((ch = buff[bi]) != '\0')
    {
        if (!insideString) {
            // Check if the current character is a double quote, indicating the start of a string
            if (ch == '"') {
                insideString = true; // Set the flag to true to indicate we're inside a string
                state = TT[state][getColType(ch)];
                lex[li] = ch;
                li++;
                bi++;
                continue;
            } else {
                bi++;
                continue;
            }
        }

        // Inside string processing
        if(!TT[state][A])
        {
          state = TT[state][getColType(ch)];
          lex[li] = ch;
          li++;
        }
        else if(li>0)
        {
            lex[li] = '\0';
            li = 0;
            if(TT[state][R]){
              bi--;
              bi--;
            }
            cout<<'<'<<lex<<','<<symbolTableID<<">\n";
            symbolTableID++;
            state = 0;
            insideString = false; // Reset the flag when the string ends
        }
        bi++;
    }
}
int main()
{
    char buff1[BUFF_SIZE];
    char buff2[BUFF_SIZE];
    string str;
    int j1=0,j2=0;
    ifstream codeFile("double_buffer.cpp");
    char buff[400] = "int a = b;\"Welcome to \\\"Compiler Construction\\\" Lab\";\nint x = 2; string uni = \"Comsats\";\0";

    //Read buffer
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
    buff1[j1] = '\0';
    buff2[j2] = '\0';

    IdentifyStringLiterals(buff);

}
