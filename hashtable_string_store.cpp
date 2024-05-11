//Lab-2
//Store each word of string in chained hashtable. Hash function will be ascii value
//of first character of the word

#include<iostream>
#include<sstream>
using namespace std;

struct List {
    string word;
    List *next;
};

//function prototypes
int countNumOfWords(string&);
void Insert(List*&, const string&);

int main() {
    string line = "Welcome to the CSC441 - Compiler Construction Lab";
    stringstream ss(line);

    List* lst = NULL;
    int i = 0;
    int n = countNumOfWords(line);
    string token[n];
    string temp;
    List* symbol_table[256]; //to store string words after parsing

    for(;i<256;i++)
    {
        symbol_table[i] = NULL;
    }

    // Insert tokens in linked list
    while (ss >> temp) {
        int val = (int)temp[0];
        Insert(symbol_table[val],temp);
    }


    for(i=0;i<256;i++)
    {
       List* t = symbol_table[i];
       while(t != NULL)
       {
         cout<<"Index: "<<i<<", Word = "<<t->word<<" "<<endl;
         t = t->next;
       }
    }
}

int countNumOfWords(string& str) {
    int count = 0;
    bool inWorld = false;

    for (char c : str) {
        if (isspace(c)) {
            inWorld = false;
        }
        else {
            if (!inWorld) {
                count++;
                inWorld = true;
            }
        }
    }
    return count;
}

void Insert(List* &head, const string& newData) {
    List* temp = new List;
    temp->word = newData;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else {
        List* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}
