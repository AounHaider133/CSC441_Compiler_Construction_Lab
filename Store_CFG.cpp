#include "production.h"
using namespace std;

void removeNullProductions(Production* start) {

}

int main() {
    Production* p1 = new Production("A");
    p1->addRuleToProd("aA");
    p1->addRuleToProd("b");
    p1->addRuleToProd("null");

    Production* p2 = new Production("B");
    p2->addRuleToProd("cB");
    p2->addRuleToProd("d");
    p2->addRuleToProd("null");

    p1->next = p2;

    cout << "Context Free Grammar (CFG):" << endl;
    p1->displayCFG();

    cout << "Removing null productions..." << endl;
    removeNullProductions(p1);

    cout << "Rules after deletion:" << endl;
    p1->displayCFG();

    return 0;
}
