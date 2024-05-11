#include "production.h"

Rule::Rule(const string& ruleName)
{
   this->r = ruleName;
   this->next = nullptr;
}
Production::Production(const string& prodName)
{
   this->name = prodName;
   this->next = nullptr;
   this->first = nullptr;
   this->last = nullptr;
}

void Production::addRuleToProd(const string& rule)
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
void Production::displayCFG()
{
      Production* temp = this;
      while(temp != nullptr)
      {
        cout<<temp->name<<"->";
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
