#include <iostream>
#include "Node.h"
#include "List.h"

List::List()
{
     head = nullptr;
}

void List::List2() 
{
     // Create while loop and run to 'delete' the linked data till nullptr
     while(length() != 0) 
     {
          Node *tmp = new Node();
          Node *a = nullptr;
          Node *b = nullptr;
          tmp->setNext(head);
          a = tmp;
          delete tmp;
     }
}

bool List::contains(std::string item) 
{
     // Use a while loop and have a temp variable run through each item till nullptr checking for 'item'.
     Node *tmp = new Node();
     tmp->setNext(head);
     return false;
}

void remove(int loc) 
{
     // 2 temporary varaibles, one holds the location of the next of the one being removed, sets it to the one before it. 
     Node *a = new Node();
     Node *b = new Node();
     int n = 0;
     a->setNext(head);
     while(n < loc) 
     {
          b = a;
          if(n == loc - 1) 
          {
               delete b;
          }   
          a->setNext(b);
          n++;
     }
}

void List::insert(std::string data)
{
     Node *tmp = new Node(data);
     tmp->setNext(head);
     head = tmp;
}

void List::insert(int loc, std::string data)
{
     Node *walker, *trailer;
     walker = this->head; 
     trailer = nullptr; 
     
     while(loc > 0 && walker != nullptr)
     {
          loc=loc-1;
          trailer=walker;
          walker = walker->getNext();
     }
     if (loc > 0)
     {
          throw std::out_of_range("Our insert is out of range");
     }

     Node *newNode = new Node(data);

     if (trailer == nullptr)
     {
          newNode->setNext(head);
          head = newNode;
     } 
     else 
     {
          newNode->setNext(walker);
          trailer->setNext(newNode);
     }
     }

     int List::length()
     {
          int count = 0;
          Node *walker = head;
          while (walker != nullptr)
          {
               count++;
               walker = walker->getNext();
          }
          return count;
}

std::string List::toString()
{
     Node *tmp = this->head;
     std::string result = "";
     while (tmp != nullptr)
     {
          result = result + tmp->getData();
          result = result + "-->";
          tmp = tmp->getNext();
     }
     result = result + "nullptr";
     return result;
}
