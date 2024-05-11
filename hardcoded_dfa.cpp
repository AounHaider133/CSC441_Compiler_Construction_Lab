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
int main()
{
    char buff[4096] = "price=price+com*sales; \0";
    char lex[100];

    int li=0,state=0;
    char ch;

    for(int bi = 0;(ch=buff[bi])!='\0';bi++)
    {
        switch(state){
    case 0:
        if(ch == '_' || isLetter(ch))
        {
            state = 1;
            lex[li] = ch;
            li++;
        }
        else{
            cout<<"Error"<<endl;
        }
        break;
    case 1:
        if(ch == '_' || isLetter(ch) || isDigit(ch))
        {
            state = 1;
            lex[li] = ch;
            li++;
        }
        else
        {
            state = 2;
        }
        break;
    case 2:
        bi--;
        bi--;
        lex[li] = '\0';
        state = 0;
        cout<<'<'<<lex<<','<<"id>\n";
        li = 0;
        break;
    }
  }
}
