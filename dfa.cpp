#include<iostream>
#include<string>
using namespace std;

void processString(string str)
{
    char lex[20];
    int state = 0;
    int li = 0;
    for(int i=0;i<str.length();i++)
    {
        //q0
        if(state == 0)
        {
            if(str[i] == 'a')
            {
                lex[li] = str[i];
                li++;
                state = 1;
            }
            else if(str[i] == 'b')
            {
                lex[li] = str[i];
                li++;
                state = 2;
            }
            else{
                cout<<"String rejected!"<<endl;
                break;
            }
        }
        //q1
        else if(state == 1)
        {
            if(str[i] == 'a' || str[i] == 'b')
            {
                lex[li] = str[i];
                li++;
                state = 2;

            }
            else{
              lex[li] = '\0';
              li = 0;
              cout<<"Matched string:"<<lex<<endl;
            }
        }
        //q2
        else if(state == 2)
        {
            cout<<"Trapped!";
            break;
        }
    }
    if(li != 0)
     cout<<"Matched string:"<<lex<<endl;
}
int main()
{
    string str_input;
    cout<<"Enter the string:";
    cin >> str_input;

    processString(str_input);
}
