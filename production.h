// production.h

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <string>
#include <iostream>
using namespace std;
class Rule
{
public:
    std::string r;
    Rule* next;

    Rule(const string& ruleName)
    {
     this->r = ruleName;
     this->next = nullptr;
    }

};

class Production
{
public:
    string name;
    Production* next;
    Rule* first;
    Rule* last;

    Production(const string& prodName)
    {
      this->name = prodName;
      this->next = nullptr;
      this->first = nullptr;
      this->last = nullptr;
    }

    void addRuleToProd(const string& rule)
    {
      Rule* newRule = new Rule(rule);
      if(this->first == nullptr)
      {
         this->first = newRule;
         this->last = newRule;
      }
      else{
         this->last->next = newRule;
         this->last = newRule;
         this->last->next = nullptr;
      }
     }

    void displayCFG()
    {
      Production* temp = this;
      while(temp != nullptr)
      {
        cout<<temp->name<<" -> ";
        Rule* rulePtr = temp->first;
        while(rulePtr != nullptr)
        {
            cout<<rulePtr->r;
            if(rulePtr->next != nullptr)
                cout<<" | ";

            rulePtr = rulePtr->next;
        }
        cout<<endl;
        temp = temp->next;
      }
     }
bool ruleExists(const std::string& rule) {
    Rule* current = first;
    while(current != nullptr) {
        if(current->r == rule) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void deleteRule(const string& r)
{
    Production* temp = this;
    while (temp != nullptr)
    {
        Rule* rulePtr = temp->first;
        if (rulePtr != nullptr && rulePtr->r == r)
        {
            temp->first = rulePtr->next;
            delete rulePtr;
            cout << "Rule deleted: " << r << endl;
            return;
        }
        while (rulePtr != nullptr && rulePtr->next != nullptr)
        {
            if (rulePtr->next->r == r)
            {
                Rule* toDelete = rulePtr->next;
                rulePtr->next = toDelete->next;
                if (toDelete == temp->last)
                {
                    temp->last = rulePtr;
                }
                delete toDelete;
                return;
            }
            rulePtr = rulePtr->next;
        }
        temp = temp->next;
    }
}
};

#endif
