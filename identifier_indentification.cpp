#include<iostream>
using namespace std;
char x;
bool T();
bool match(char);
void Id();
void print(string,string);
int offset = 0;
string code = "bool x = a + b;";
int main()
{
bool x   =    false ;
    if(T())
    {
        if(match(' '))
        {
            Id();
            if(match('='))
            {
                print("=","Term");
            }
            if(match(';'))
            {
                print(";","EOF");
                return 0;
            }
            offset--;
            while(match(' '))
            {
                //cout<<"x";
                offset++;
            }
            offset--;
        string id = "";
        while(!match('+') || !match('-') || !match('*') || !match('/') || !match('='))
        {
            id += code[offset];
            offset++;
        }
        print(id,"Identifier");
        offset--;
        }
    }
}
bool match(char c)
{
    if(c == code[offset])
    {
        offset++;
        return true;
    }
    return false;
}
bool T()
{
    //int case
    if(match('i'))
    {
        if(match('n'))
        {
            if(match('t'))
            {
                print("int","keyword");
                return true;
            }
        }
    }
    //float case
    if(match('f'))
    {
        if(match('l'))
        {
            if(match('o'))
            {
                if(match('a'))
                {
                    if(match('t'))
                    {
                        print("float","keyword");
                        return true;
                    }
                }
            }
        }
    }
    //double case
    if(match('d'))
    {
        if(match('o'))
        {
            if(match('u'))
            {
                if(match('b'))
                {
                    if(match('l'))
                    {
                        if(match('e'))
                        {
                            print("double","keyword");
                            return true;
                        }
                    }
                }
            }
        }
    }
    //char case
    if(match('c'))
    {
        if(match('h'))
        {
            if(match('a'))
            {
                if(match('r'))
                {
                    print("char","keyword");
                    return true;
                }
            }
        }
    }
    //bool case
    if(match('b'))
    {
        if(match('o'))
        {
            if(match('o'))
            {
                if(match('l'))
                {
                    print("bool","keyword");
                    return true;
                }
            }
        }
    }
    //string case
    if(match('s'))
    {
        if(match('t'))
        {
            if(match('r'))
            {
                if(match('i'))
                {
                    if(match('n'))
                    {
                        if(match('g'))
                        {
                            print("string","keyword");
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
void Id()
{
    string id = "";
    while(!match(' ') || !match('='))
    {
        id += code[offset];
        offset++;
    }
       print(id,"Identifier");
       offset--;
}
void print(string value,string id)
{
    cout<<value<<" : "<<id<<endl;
}
