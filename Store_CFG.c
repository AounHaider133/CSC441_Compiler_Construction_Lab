#include<iostream>
using namespace std;

struct Production{
 string name;
 Production *next;
 Rule *first;
 Rule *last;
}prod;
struct Rule{
 string *r;
 Rule *next;
}rule;

int main()
{
    cout<<"XYZ";
}
