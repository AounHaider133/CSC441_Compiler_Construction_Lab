#include <iostream>
using namespace std;

void IdentifyString(const char* code) {
    bool inString = false;
    int start = 0;

    for (int i = 0; code[i] != '\0'; ++i) {
        // If the current character is a double quote and we are not already inside a string
        if (code[i] == '"' && !inString) {
            // Set inString flag to true
            inString = true;
            // Store the starting position of the string literal
            start = i;
        }
        // If the current character is a double quote and we are inside a string
        else if (code[i] == '"' && inString) {
            // Print the string literal from start to the current position
            cout << "String Literal: ";
            for (int p = start; p <= i; ++p) {
                cout << code[p];
            }
            cout << endl;
            // Reset inString flag to false
            inString = false;
        }
    }
}

int main() {
    char buff[300] = "string str = \"Compiler class!\";\nint x = 2;\nstring section = \"A\";";
    cout << "Source Code:" << endl;
    cout<<"----------------------------"<<endl;
    cout << buff << endl;
    cout<<"----------------------------"<<endl;

    cout << "String Literals:" << endl;
    IdentifyString(buff);

    return 0;
}
