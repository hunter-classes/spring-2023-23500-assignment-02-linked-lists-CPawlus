#pragma once
#include <iostream>
#include "Node.h"

class List{
     private:
          Node *head;
     public:
          List();
          void insert(std::string data);
          void insert(int loc, std::string data); 
          int length();
          std::string toString(); 

          // Part 1
          bool contains(std::string item);
          void remove(int loc);
          void List2();
};