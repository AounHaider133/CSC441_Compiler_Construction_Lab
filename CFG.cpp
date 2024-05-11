#include<iostream>
using namespace std;

class Rule
{
   public:
   string r;
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
};

int main()
{
    Production* p1 = new Production("A");
    p1->addRuleToProd("aA");
    p1->addRuleToProd("b");
    p1->addRuleToProd("e");

    Production* p2 = new Production("B");
    p2->addRuleToProd("cB");
    p2->addRuleToProd("d");

    p1->next = p2;

    p1->displayCFG();
}
