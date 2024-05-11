// removal.h

#ifndef REMOVAL_H
#define REMOVAL_H

#include "production.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include<cctype>
using namespace std;

bool isLowerCase(const string& str) {
    return all_of(str.begin(), str.end(), [](unsigned char c) { return islower(c); });
}

bool ruleExists(Rule* first, const string& ruleToCheck) {
    Rule* current = first;
    while(current != nullptr) {
        if(current->r == ruleToCheck) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
void removeNullProductions(Production* start) {
    vector<string> null_nonTerminal;
    Production* temp = start;

    // Store non-terminals having null production in vector 'null_nonTerminal'
    while(temp != nullptr) {
        Rule* ruleTemp = temp->first;
        while(ruleTemp != nullptr) {
            if(ruleTemp->r == "null") {
                null_nonTerminal.push_back(temp->name);
                // Remove the rule that is completely null
                temp->deleteRule(ruleTemp->r);
            }
            ruleTemp = ruleTemp->next;
        }
        temp = temp->next;
    }

    // Iterate over all productions
    temp = start;
    while(temp != nullptr) {
        Rule* ruleTemp = temp->first;
        vector<string> newRules;

        // Iterate over all rules of the current production
        while(ruleTemp != nullptr) {
            string currentRule = ruleTemp->r;
            // Skip the null rules
            if(currentRule != "null") {
                // Generate all combinations of the rule without the null non-terminals
                for(const string& nt : null_nonTerminal) {
                    size_t pos;
                    // While the non-terminal is found in the rule, create new rule variants
                    while((pos = currentRule.find(nt)) != string::npos) {
                        string newRule = currentRule;
                        newRule.erase(pos, nt.length());
                        // Avoid adding duplicate or empty rules
                        if(!newRule.empty() && find(newRules.begin(), newRules.end(), newRule) == newRules.end() &&
                           !ruleExists(temp->first, newRule)) { // Check if the rule already exists
                            newRules.push_back(newRule);
                        }
                        // Replace the non-terminal with a space to check for further occurrences
                        currentRule.replace(pos, nt.length(), " ");
                    }
                }
            }
            ruleTemp = ruleTemp->next;
        }

        // Add the new rules to the production
        for(const string& newRule : newRules) {
            temp->addRuleToProd(newRule);
        }

        // Remove the original null production rules
        for(const string& nt : null_nonTerminal) {
            temp->deleteRule(nt + "->null");
        }

        temp = temp->next;
    }
}
void removeRedundantProduction(Production* p)
{
    Production* temp = p;
    while(temp != nullptr)
    {
        Rule* r1 = temp->first;
        while(r1 != nullptr)
        {
            Rule* r2 = temp->first;
            Rule* prevNode = nullptr;
            while(r2 != nullptr)
            {
                if(r1 != r2)
                {
                    string a = r1->r;
                    string b = r2->r;
                    trim(a); trim(b);
                    if(a == b)
                    {
                        // Remove the redundant node
                        Rule* redundantNode = r2;
                        if(prevNode != nullptr)
                        {
                            prevNode->next = r2->next;
                        }
                        else
                        {
                            temp->first = r2->next;
                        }
                        r2 = r2->next;
                        delete redundantNode;
                        continue;
                    }
                 }
                prevNode = r2;
                r2 = r2->next;
            }
            r1 = r1->next;
        }
        temp = temp->next;
    }
}
// Function to find a production by its non-terminal symbol
Production* findProduction(Production* start, const string& nonTerminal) {
    Production* temp = start;
    while (temp != nullptr) {
        if (temp->name == nonTerminal) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void removeUnitProductions(Production* start) {
    Production* temp = start;
    while (temp != nullptr) {
        Rule* rulePtr = temp->first;
        while (rulePtr != nullptr) {
            string rule = rulePtr->r;
            if (rule.length() == 1 && isupper(rule[0])) {
                Production* nonTerminalProduction = findProduction(start, rule);
                if (nonTerminalProduction != nullptr) {
                    // Add rules of non-terminal production to current production
                    Rule* nonTerminalRulePtr = nonTerminalProduction->first;
                    while (nonTerminalRulePtr != nullptr) {
                        if (!start->ruleExists(nonTerminalRulePtr->r) && isLowerCase(nonTerminalRulePtr->r)) {
                            temp->addRuleToProd(nonTerminalRulePtr->r);
                        }
                        nonTerminalRulePtr = nonTerminalRulePtr->next;
                    }
                    // Remove the unit production
                    temp->deleteRule(rule);
                }
            }
            rulePtr = rulePtr->next;
        }
        temp = temp->next;
    }
}
#endif
