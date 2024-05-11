//CSC441 - Compiler Construction
//Lab Assignment 1
//Name: Mr. Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: Mam Gul Bano
//Spring2024
#include<iostream>
#include<string>
#include<regex>
using namespace std;
bool isKeyword(string);
int main()
{
    regex re1("[a-zA-Z_][a-zA-Z0-9]*"); //identifier
    regex re2("if|else|int|float|double|bool|char|break|continue|string"); //keywords
    regex re3("[+-]?\\d+\\.\\d+e[+-]?\\d+"); //exponential numbers
    regex re4("[+-]?\\d+\\.\\d+"); //float numbers
    regex re5("\\d+"); //digits
    regex re6("\\|\\||&&|==|!=|<=|>=|<|>"); //logical operators
    string test_str = "int x = 5;float m = -2.3;if(x>=m){x=2;}else if(x==3){m=2}";
    string temp = test_str;
    smatch match1,match2,match3,match4,match5,match6;
    int numOfTokens = 0;

    cout<<"--------------------"<<endl;
    cout<<"Lexical Analyzer:"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Input:"<<test_str<<endl<<endl;
    cout<<"--------------------"<<endl;
    cout<<"TOKENS:"<<endl;
    cout<<"--------------------"<<endl;
    //Identifiers
    while(regex_search(temp,match1,re1))
    {
        if(isKeyword((string)match1[0])){
            temp = match1.suffix();
            continue;
        }

        cout<<"(identifier):"<<match1[0]<<endl;
        temp = match1.suffix();
        numOfTokens++;
    }
    temp = test_str;
    //Keywords
    while(regex_search(temp,match2,re2))
    {
        cout<<"(keyword):"<<match2[0]<<endl;
        temp = match2.suffix();
        numOfTokens++;
    }
    temp = test_str;
    //Operators
    while(regex_search(temp,match3,re3))
    {
        cout<<"(exp-number):"<<match3[0]<<endl;
        temp = match3.suffix();
        numOfTokens++;
    }
    temp = test_str;
    //Float numbers
    while(regex_search(temp,match4,re4))
    {
        cout<<"(float-number):"<<match4[0]<<endl;
        temp = match4.suffix();
        numOfTokens++;
    }
    temp = test_str;
    //Digits
    while(regex_search(temp,match5,re5))
    {
        cout<<"(digit):"<<match5[0]<<endl;
        temp = match5.suffix();
        numOfTokens++;
    }
    temp = test_str;
    //Logical Operators
    while(regex_search(temp,match6,re6))
    {
        cout<<"(logical-operator):"<<match6[0]<<endl;
        temp = match6.suffix();
        numOfTokens++;
    }
        cout<<"--------------------"<<endl;
        cout<<"Total # of tokens:"<<numOfTokens<<endl;
        cout<<"--------------------"<<endl;
        return 0;
}
bool isKeyword(string token)
{
    if(token == "if" ||token == "else" || token == "int" || token == "float" ||
       token == "double" || token == "bool" || token == "char" || token == "continue"
       || token == "break" || token == "string")
        return true;
    return false;
}
