#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int isKeyword(char buff[])
{
   char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                         "do","double","else","enum","extern","float","for","goto",
                         "if","int","long","register","return","short","signed",
                         "sizeof","static","struct","switch","typedef","union",
                         "unsigned","void","volatile","while"};
    int flag=0;
    for(int i=0;i<32;i++)
    {
        if(strcmp(keywords[i],buff)==0)
        {
            flag = 1;
            break;
        }
    }
    return flag;

}
int main()
{
    char ch,buffer[15],operators[] = "+-*/%=";
    ifstream fin("double_buffer.cpp");
    int i,j=0;
    if(!fin.is_open())
    {
        cout<<"Error while opening file."<<endl;
        return 1;
    }
    while(!fin.eof())
    {
        ch = fin.get();
        for(i=0;i<6;i++)
        {
            if(ch == operators[i])
             cout<<ch<<" is operator"<<endl;
        }
        if(isalnum(ch))
            buffer[j++] = ch;
        else if((ch == ' ' || ch == '\n')&&(j != 0)){
            buffer[j] = '\0';
            j = 0;
        }
        if(isKeyword(buffer))
            cout<<buffer<<" is keyword"<<endl;
        else
            cout<<buffer<<" is identifier"<<endl;

    }
    fin.close();
    return 0;
}
