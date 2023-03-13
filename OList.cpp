#include <iostream>
#include <string>
#include "Node.h"
#include "OList.h"

OList::OList()
{
     head = nullptr;
}

OList::~OList()
{
     std::cerr << "Calling the destructor\n";
     Node *walker = head;
     Node *trailer = nullptr;
     while (walker != nullptr){
          trailer=  walker;
          walker = walker->getNext();
          std::cerr << "Deleting " << trailer->getData() << ", ";
          delete trailer;
     }
     std::cerr << "\n";
}

void OList::reverse() 
{
     Node *walker = head, *trailer = nullptr, *aheader = nullptr;
     while(walker != nullptr) 
     {
          aheader = walker->getNext();
          walker->setNext(trailer);
          trailer = walker;
          walker = aheader;
     }
     this->head = trailer; 
}

std::string OList::get(int loc) 
{
     Node *walker = head;
     int c = 0;
     while (walker != nullptr)
     {
          if(c == loc) 
          {
               return walker->getData();
          }
          walker = walker->getNext();
          c++;
     }
     return "";
} 

bool OList::contains(std::string data) 
{
     Node *walker = head;
     while (walker != nullptr)
     {
          if(walker->getData() == data) 
          {
               return true;
          }
          walker = walker->getNext();
     }
     return false;
}

void OList::insert(std::string data)
{
     if(head == nullptr) 
     {
          Node *tmp = new Node(data);
          head = tmp;
     }
     else 
     {
          Node *tmp = new Node(data);
          Node *walker = head, *trailer = nullptr;
          
          while(walker != nullptr && (std::stoi(walker->getData()) < std::stoi(tmp->getData()))) 
          {
               trailer = walker;
               walker = walker->getNext();
          }
          if(trailer == nullptr) 
          {
               tmp->setNext(head);
               head = tmp;
          }
          else 
          {
               tmp->setNext(walker);
               trailer->setNext(tmp);
          } 
     }
}

int OList::length(){
     int count = 0;
     Node *walker = head;
     while (walker != nullptr){
          count++;
          walker = walker->getNext();
     }
     return count;
}

void OList::remove(int loc)
{
     Node *walker, *trailer;
     walker = this->head;
     trailer = nullptr; 
     
     while(loc>0 && walker != nullptr)
     {
          loc=loc-1;
          trailer=walker;
          walker = walker->getNext();
     }
     if (walker == nullptr)
     {
          throw std::out_of_range("Tried to remove out of range");
     }
     if (trailer == nullptr)
     {
          head = walker->getNext();
          delete walker;
     } 
     else 
     {
          trailer->setNext(walker->getNext());
          delete walker;
     }
}

std::string OList::toString()
{
     Node *tmp = this->head;
     std::string result = "";
     while (tmp != nullptr){
          result = result + tmp->getData();
          result = result + "-->";
          tmp = tmp->getNext();
     }
     result = result + "nullptr";
     return result;
}
