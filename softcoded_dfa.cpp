#include<iostream>
using namespace std;

bool isLetter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
bool isDigit(char ch)
{
    return ((ch >= '0' && ch <= '9'));
}
enum COL{
    L=0,U,D,NLDU,A,R,T
};
COL getColType(char ch)
{
    if(isLetter(ch)) return L;
    else if(isDigit(ch)) return D;
    else if(ch == '_') return U;
    return NLDU;
}
int main()
{
    enum TOK{
      N=0,ID,KEY,PUN,OP,LIT
    };

    char buff[4096] = "price+=price2+com*sales; \0";
    char lex[100];

    int Transition_Table[3][7] = {
    {1,1,-1,-1,false,false,N},
    {1,1,1,2,false,false,N},
    {0,0,0,0,true,true,ID}
    };
    int bi=0,li=0,state=0;
    char ch;
    int numOfValidInputs = 3;
    int symbolTableID=0;
    while((ch=buff[bi])!='\0')
    {
        if(!Transition_Table[state][A] && getColType(ch)<numOfValidInputs)
        {
          state = Transition_Table[state][getColType(ch)];
          lex[li] = ch;
          li++;
        }
        else if(li>0)
        {
            lex[li] = '\0';
            li = 0;
            if(Transition_Table[state][R]){
              bi--;
            }
            cout<<'<'<<lex<<','<<symbolTableID<<">\n";
            symbolTableID++;
            state = 0;
        }
        bi++;
    }
}
