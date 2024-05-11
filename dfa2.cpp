//Implement a program which support language on a*b* via DFA states
#include<iostream>
#include<string>
using namespace std;

void processString(string str)
{
    char lex[20];
    int state = 1;
    int li = 0;
    //S = 1, A = 2, R = 3
    for(int i=0;i<str.length();i++)
    {
        switch(state)
        {
            case 1:
                if(str[i] == 'a')
                {
                    lex[li] = str[i];
                    li++;
                }
                else if(str[i] == 'b')
                {
                    state = 2;
                    lex[li] = str[i];
                    li++;
                }
                break;

            case 2:
                if(str[i] == 'b')
                {
                    lex[li] = str[i];
                    li++;
                }
                else if(str[i] == 'a')
                {
                    state = 3;
                }
                break;

            case 3:
                if(str[i] == 'a' || str[i] == 'b')
                {
                    state = 3;
                }
                break;
        }
    }
    lex[li] = '\0';
    cout<<"Matched string:"<<lex<<endl;

}
int main()
{
    string str_input;
    cout<<"Enter the string:";
    cin >> str_input;

    processString(str_input);
}
