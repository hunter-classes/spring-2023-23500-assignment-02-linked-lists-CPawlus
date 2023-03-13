#pragma once
#include <iostream>
#include "node.h"

class OList
{
     private:
          Node *head;
     public:
          OList();
          ~OList();
          void insert(std::string data);
          std::string toString(); 
          bool contains(std::string data);
          std::string get(int loc);
          void remove(int loc);
          void reverse();
          std::string find(std::string data);
          int length();
};