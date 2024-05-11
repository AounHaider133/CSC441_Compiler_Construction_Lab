//[a-zA-Z_][a-zA-Z0-9]*
//[0-9]+\\.[0-9]+   (simple float numbers)
//^[+-]?[0-9]+\\.[0-9]+\\e\\^[+-]?[0-9]+$ (complex float numbers)
//^[+-]?\\d+\\.\\d+\\e\\^[+-]?\\d+$
#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main()
{
    regex re("^[0-9]+\\.[0-9]+$");
    string test_str = "11.33";
    smatch match;
    while(regex_search(test_str,match,re))
    {
        cout<<"Match found!"<<endl;
        test_str = match.suffix();

    }
}
