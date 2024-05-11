#include<iostream>
using namespace std;

int main()
{
  int x,y;
  char op;

  cout<<"Enter operand#1:";
  cin>>x;
  cout<<"Enter operand#2:";
  cin>>y;

  cout<<"Select operator(+,-,*,/):";
  cin>>op;

  switch(op)
  {
    case '+':
     cout<<"Result="<<(x+y);
    break;

    case '-':
     cout<<"Result="<<(x-y);
    break;

    case '*':
     cout<<"Result="<<(x*y);
    break;

    case '/':
     cout<<"Result="<<(x/y);
    break;

    default:
      cout<<"Invalid option selected!";
    break;
  }
}
