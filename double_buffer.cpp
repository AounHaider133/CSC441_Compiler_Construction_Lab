//Synopsis: Identify identifiers using double buffer.
#include<iostream>
#include<fstream>
#include<string>
#define BUFF_SIZE 500
using namespace std;
void printIdentifiers(string str);
bool isValidIdentifier(string identifier);

int main()
{
  char* buff1 = new char[BUFF_SIZE];
  char* buff2 = new char[BUFF_SIZE];
  string str;
  int i,j=0,j1=0;
  ifstream codeFile("file.cpp");

  while(getline(codeFile,str))
  {
      i=0;
      while(i < str.length() && j<BUFF_SIZE){
       buff1[j] = str[i];
       i++; j++;
      }
      if(j<BUFF_SIZE)
      buff1[j++] = '\n';

      if(j == BUFF_SIZE)
      {
          while(i < str.length() && j1<BUFF_SIZE){
          buff2[j1] = str[i];
          i++; j1++;
      }
       if(j1<BUFF_SIZE)
         buff2[j1++] = '\n';
      }

  }
  //cout<<buff1;
  //cout<<endl<<"Buffer 1 size filled:"<<j;

  //cout<<endl<<buff2;
  //cout<<endl<<"Buffer 2 size filled:"<<j1;

  printIdentifiers(buff1);
  printIdentifiers(buff2);

  delete[] buff1,buff2;

}

bool isValidIdentifier(string identifier) {
    if (identifier.empty() || !(isalpha(identifier[0]) || identifier[0] == '_'))
        return false;

    for (int i = 1; i < identifier.size(); ++i) {
        if (!(isalnum(identifier[i]) || identifier[i] == '_'))
            return false;
    }

    return true;
}
void printIdentifiers(string str) {
    string identifier;
    bool inIdentifier = false;

    for (char c : str) {
        if (isalnum(c) || c == '_') {
            if (!inIdentifier) {
                inIdentifier = true;
                identifier.clear();
            }
            identifier += c;
        } else {
            if (inIdentifier) {
                if (isValidIdentifier(identifier)) {
                    cout << "Identifier found: " << identifier <<endl;
                }
                inIdentifier = false;
            }
        }
    }

    if (inIdentifier && isValidIdentifier(identifier)) {
        cout << "Identifier found: " << identifier << endl;
    }
}
