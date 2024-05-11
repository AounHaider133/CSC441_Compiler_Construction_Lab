#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  string str = "Welcome to Compiler Construction Lab!";
  str.erase(remove_if(str.begin(), str.end(), [](char c) { return std::isspace(c); }), str.end());

  cout<<str;
}
