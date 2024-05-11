//[a-zA-Z_][a-zA-Z0-9]*
//[+\\*-/]
//[a-zA-Z_][a-zA-Z0-9]* (identifier)
//[0-9]+\\.[0-9]+   (simple float numbers)
//^[+-]?[0-9]+\\.[0-9]+\\e\\^[+-]?[0-9]+$ (complex float numbers)
//^[+-]?\\d+\\.\\d+\\e\\^[+-]?\\d+$ (exponential float number)
//\\|\\||&&|==|!=|<=|>=|<|> (comparison operator)
//identifier,keyword,operator,digit,float,exponential,logical operator

#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main()
{
    regex re("\\d+");
    string test_str = "int x = 133;";
    smatch match;
    while(regex_search(test_str,match,re))
    {
        cout<<"Match found:"<<match[0]<<endl;
        //cout<<test_str;
        test_str = match.suffix();

    }
}
