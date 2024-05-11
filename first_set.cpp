#include "production.h"
#include "removal.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <map>
#include <cctype>
using namespace std;

// Function to find and print the first set of a given grammar
void findAndPrintFirstSet(Production* start) {
    // Map to store the first set of each non-terminal
    map<string, unordered_set<string>> firstSets;

    // Traverse each production
    Production* currentProduction = start;
    while (currentProduction != nullptr) {
        // Initialize first set for the current non-terminal
        string nonTerminal = currentProduction->name;
        firstSets[nonTerminal] = unordered_set<string>();

        // Traverse each rule of the current production
        Rule* currentRule = currentProduction->first;
        while (currentRule != nullptr) {
            string rule = currentRule->r;

            // If the rule starts with a terminal, add it to the first set
            if (islower(rule[0])) {
                firstSets[nonTerminal].insert(rule.substr(0, 1));
            }

            // If the rule starts with a non-terminal, add its first set
            else if (isupper(rule[0])) {
                firstSets[nonTerminal].insert(firstSets[rule].begin(), firstSets[rule].end());
            }

            // Move to the next rule
            currentRule = currentRule->next;
        }

        // Move to the next production
        currentProduction = currentProduction->next;
    }

    // Print the first sets
    for (const auto& pair : firstSets) {
        cout << "First(" << pair.first << "): { ";
        for (const auto& terminal : pair.second) {
            cout << terminal << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    Production* p1 = new Production("A");
    p1->addRuleToProd("B");
    p1->addRuleToProd("b");
    p1->addRuleToProd("a");
    p1->addRuleToProd("null");

    Production* p2 = new Production("B");
    p2->addRuleToProd("BaA");
    p2->addRuleToProd("x");
    p2->addRuleToProd("y");

    p1->next = p2;

    cout << "Context Free Grammar (CFG):" << endl;
    p1->displayCFG();

    cout << endl << "After removing null productions:" << endl;
    removeNullProductions(p1);
    p1->displayCFG();

    cout << endl << "After removing unit productions:" << endl;
    removeUnitProductions(p1);

    removeRedundantProduction(p1);
    p1->displayCFG();

    cout << endl << "First sets of the grammar:" << endl;
    findAndPrintFirstSet(p1);

    return 0;
}
