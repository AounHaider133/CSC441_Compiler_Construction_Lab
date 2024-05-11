//CSC441 - Compiler Construction
//Midterm Question no.01
//Name: Mr. Aoun-Haider
//ID: FA21-BSE-133
//Submitted to: Mam Gul Bano
//Spring2024
#include <iostream>
#include <string>
using namespace std;

enum State { START, A, AB, ABA, DEAD };

State transition(State current, char input) {
    switch (current) {
        case START:
        case ABA:
            if (input == 'a') return A;
            if (input == 'b') return START;
            break;
        case A:
            if (input == 'a') return A;
            if (input == 'b') return AB;
            break;
        case AB:
            if (input == 'a') return ABA;
            if (input == 'b') return START;
            break;
        default:
            return DEAD;
    }
    return DEAD;
}

bool accepts(const string &s) {
    State current = START;
    for (char c : s) {
        current = transition(current, c);
        if (current == DEAD) return false;
    }
    return current == ABA || current == A || current == START;
}

int main() {
    string s;
    cout << "Enter a string to check: ";
    cin >> s;

    if (accepts(s)) {
        cout << "The string is accepted by the DFA." << endl;
    } else {
        cout << "The string is not accepted by the DFA." << endl;
    }

    return 0;
}
