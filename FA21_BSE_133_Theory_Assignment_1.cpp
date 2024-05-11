//CSC441-Compiler Construction
//Theory Assignment: 01
//Name: Mr. Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: M Bilal Arshad
#include<iostream>
using namespace std;

enum COL{
    I=0,F,W,H,L,E,DOLLAR,LETTER,UNDERSCORE,QUOTE,DIGIT,EQ,NOT,PUNC,SLASH,STAR,OTHER,A,R,T
};

COL getColType(char);
bool isLetter(char);
bool isDigit(char);
bool isPunc(char);
bool isOp(char);

int main()
{
    enum TOK{
      N=0,IDENTIFIER,KEYWORD,STRING,COMMENT,LITERAL,OPERATOR,PUNCTUATION
    };

    string tokens[8] = {"N","IDENTIFIER","KEYWORD","STRING","COMMENT","LITERAL","OPERATOR","PUNCTUATION"};
    char buff[4096] = "if($x > 55)\n{\n  $name = 'mr.aoun-haider'; /*assignment*/\n  $x = $x + 1;\n}\n  echo 'Welcome to Compiler Lab';";
    char lex[100];

    cout<<"PHP Mini Source Code:"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<buff<<endl;
    cout<<"------------------------------"<<endl;

    int Transition_Table[24][20] = {
    {1,-1,3,-1,-1,-1,8,-1,-1,10,13,14,16,17,18,-1,-1,false,false,N},
    {-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,KEYWORD},
    {-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {-1,-1,-1,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,KEYWORD},
    {9,9,9,9,9,9,-1,9,9,-1,-1,-1,-1,-1,-1,-1,-1,false,false,N},
    {9,9,9,9,9,9,-1,9,9,-1,9,-1,-1,-1,-1,-1,22,false,false,N},
    {10,10,10,10,10,10,10,10,10,11,10,10,10,10,10,10,10,false,false,N},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,STRING},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,STRING},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,23,true,true,LITERAL},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,15,-1,-1,-1,-1,-1,true,false,OPERATOR},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,OPERATOR},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,false,false,N},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,PUNCTUATION},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,false,false,N},
    {19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,20,19,false,false,N},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1,-1,false,false,N},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,COMMENT},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,IDENTIFIER},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,true,true,LITERAL},
    };
    int bi=0,li=0,state=0;
    char ch;
    int numOfValidInputs = 16;
    int symbolTableID=0;
    while((ch=buff[bi])!='\0')
    {

        if(!Transition_Table[state][A])
        {
          state = Transition_Table[state][getColType(ch)];
          if(state == -1){
            state = 0;
            li = 0;
          }
          else{
            //cout<<state<<endl;
            lex[li] = ch;
            li++;
          }
        }
        else if(li>0)
        {
            lex[li] = '\0';
            li = 0;
            cout<<'<'<<lex<<','<<symbolTableID<<"> - "<<tokens[Transition_Table[state][19]]<<endl;
            if(Transition_Table[state][R]){
              bi--;
            }
            symbolTableID++;
            state = 0;
        }
        bi++;
    }

    //For Remaining characters
    if(li>0)
    {
        lex[li] = '\0';
        cout<<'<'<<lex<<','<<symbolTableID<<"> - "<<tokens[Transition_Table[state][19]]<<endl;
     }
     return 0;
}
COL getColType(char ch)
{
    if(ch == 'i') return I;
    else if(ch == 'f') return F;
    else if(ch == 'w') return W;
    else if(ch == 'h') return H;
    else if(ch == 'i') return I;
    else if(ch == 'l') return L;
    else if(ch == 'e') return E;
    else if(ch == '$') return DOLLAR;
    else if(ch == '/') return SLASH;
    else if(ch == '\'') return QUOTE;
    else if(isLetter(ch)) return LETTER;
    else if(isDigit(ch)) return DIGIT;
    else if(isPunc(ch)) return PUNC;
    else if(ch == '!') return NOT;
    else if(ch == '=') return EQ;
    else if(ch == '_') return UNDERSCORE;
    else if(ch == '*') return STAR;
    return OTHER;
}
bool isLetter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
bool isDigit(char ch)
{
    return ((ch >= '0' && ch <= '9'));
}
bool isPunc(char ch)
{
    return ((ch == '(') || (ch == ')') || (ch == '{') || (ch == '}') || (ch == ';') || (ch == ','));
}
bool isOp(char ch)
{
    return ((ch == '=') || (ch == '!'));
}
