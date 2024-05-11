#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void firstSet(char,int,int);
int count,n=0;
char calc_first[10][100];
int m = 0;

//To store production rules
char production[10][100];
char f[10],first[10];
int k,e;
char ck;
int main()
{
    int jm = 0;
    int km = 0;
    int i,choice;
    char c,ch;
    count = 8;

    strcpy(production[0],"X=TnS");
    strcpy(production[1],"X=Rm");
    strcpy(production[2],"T=q");
    strcpy(production[3],"T=^");
    strcpy(production[4],"S=p");
    strcpy(production[5],"S=^");
    strcpy(production[6],"R=om");
    strcpy(production[7],"R=TS");

    int kay;
    char done[count];
    int ptr = -1;

    //initializing the calc_first array
    for(k=0;k<count;k++)
    {
        for(kay=0;kay<100;kay++)
        {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0,point2,xxx;

    for(k=0;k<count;k++)
    {
        c = production[k][0];
        point2 = 0;
        xxx = 0;

        //Is First() of c already computed
        for(kay = 0;kay<=ptr;kay++)
        {
            if(c == done[kay])
                xxx = 1;
        }

        if(xxx == 1)
            continue;

        firstSet(c,0,0);
        ptr += 1;

        done[ptr] = c;
        cout<<"\n First("<<c<<") = { ";
        calc_first[point1][point2++] = c;

        //Display first() set of grammer
        for(i=0+jm;i<n;i++)
        {
            int lark = 0,chk = 0;
            for(lark = 0;lark<point2;lark++)
            {
                if(first[i] == calc_first[point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
            {
                cout<<first[i]<<", ";
                calc_first[point1][point2++] = first[i];
            }
        }
        cout<<"}"<<endl;
        jm =n;
        point1++;
    }
    cout<<endl;
    cout<<"----------------------------------"<<endl<<endl;
    //char done[count];
}
void firstSet(char c,int q1,int q2)
{
    int j;
    //Is Non-Terminal??
    if(!isupper(c))
    {
        first[n++] = c;
    }
    for(j=0;j<count;j++)
    {
        if(production[j][0] == c)
        {
            if(production[j][2] == '^'){
                if(production[q1][q2] != '\0')
                    first[n++] = '^';
                else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                {
                    firstSet(production[q1][q2],q1,(q1+1));
                }
                else
                    first[n++] = '^';
            }
            else if(!isupper(production[j][2])){
                first[n++] = production[j][2];
            }
            else{
                firstSet(production[j][2],j,3);
            }
        }
    }
}
