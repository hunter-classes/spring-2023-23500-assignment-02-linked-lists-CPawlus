#include <iostream>
#include "List.h"

int main()
{
     List *a = new List();
     a->insert(0, "First");
     a->insert(1, "Third");
     a->insert(2, "Second");
     a->insert(3, "Fourth");
     std::cout << a->toString() << " " << a->length() << "\n";
     a->List2();
     std::cout << a->toString() << " " << a->length() << "\n";
     return 0;
}