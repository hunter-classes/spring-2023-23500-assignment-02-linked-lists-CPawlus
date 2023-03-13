#include <iostream>
#include "OList.h"
#include "node.h"

int main()
{
     OList *a = new OList();
     a->insert("5");
     a->insert("18");
     a->insert("10");
     a->insert("6");
     std::cout << a->toString() << "\n";
     a->reverse();
     std::cout << a->toString() << "\n";
     return 0;
}