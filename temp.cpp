#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const int BUFF_SIZE = 4096;

bool isLetter(char c)
{
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}
bool isDigit(char c)
{
    return (c>='0' && c<='9');
}

void processBuffer(const vector<char> &buffer,int Size)
{
    char lex[20];
    int i = 0;
    int li = 0;
    int state = 0;
    for(int i=0;i<Size;i++)
    {
        if(state == 0)
        {
            if(isLetter(buffer[i]) || buffer[i] == '_')
            {
                lex[li] = buffer[i];
                i++;
                state = 1;
            }
            else{
                state = 1;
            }
        }
        else if(state == 1)
        {
            if (isLetter(buffer[i]) || buffer[i] == '_' || isDigit(buffer[i]))
            {
                lex[li] = buffer[i];
                li++;
            }
            else
            {
                lex[li] = '\0';
                li = 0;
                state = 0;
                cout<<"Identifier: "<<lex<<endl;
            }
        }
        else if(state == 2)
        {
            state = 0;
        }
    }
}
int main()
{
    ifstream file("double_buffer.cpp",ios::binary);

    if(!file.is_open())
    {
        cout<<"Error while opening file!"<<endl;
        return 1;
    }
    bool useBuff = true;
    vector<char> buff1(BUFF_SIZE);
    vector<char> buff2(BUFF_SIZE);

    while(!file.eof())
    {
        if(useBuff)
        {
            file.read(buff1.data(),BUFF_SIZE);
            processBuffer(vector<char>(buff1.begin(),buff1.begin() + file.gcount()),file.gcount());
        }
        else
        {
            file.read(buff2.data(),BUFF_SIZE);
            processBuffer(vector<char>(buff2.begin(),buff2.begin()+file.gcount()),file.gcount());
        }
        useBuff = !useBuff;
    }
    file.close();
}
