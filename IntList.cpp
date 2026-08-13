#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList()
{
  dummyHead = nullptr;
  dummyTail = nullptr;
}

IntList::~IntList()
{
  while(dummyHead != nullptr)
    {
      IntNode* temp = dummyHead;
      dummyHead = dummyHead->next;
      delete temp;
    }
}

void IntList::push_front(int value)
{
  IntNode* newNode = new IntNode(value);
  newNode->next = dummyHead->next;
  newNode->prev = dummyHead;
  dummyHead->next->prev = newNode;
  dummyHead->next = newNode;
}

void IntList::pop_front()
{
  if(dummyHead == nullptr)
  {
    return;
  }
  else
  {
    IntNode* temp = dummyHead;
    dummyHead = dummyHead->next;
    delete temp;
  }
}

void IntList::push_back(int value) //Inserts a data value (within a new node) at the back end of the list. This must be an O(1) operation.
{
  IntNode* newNode = new IntNode(value);
  if(dummyHead == nullptr)
  {
    dummyTail = newNode;
  }
  else
  {
    newNode->prev = dummyTail;
    dummyTail = newNode;
  }
}

void IntList::pop_back() //Removes the node at the back end of the list (the node before the dummy tail). Does nothing if the list is already empty. This must be an O(1) operation.
{
  if(dummyHead == nullptr)
  {
    return;
  }
  else
  {
    IntNode* temp = dummyTail;
    dummyTail = dummyTail->prev;
    delete temp;

  }
}

bool IntList::empty() const //Returns true if the list does not store any data values (it only has dummy head and dummy tail), otherwise returns false.
{
  return dummyHead->next == dummyTail;
}

ostream & operator<<(ostream &out, const IntList &rhs) //A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
{
  IntNode *current = rhs.dummyHead->next;
  while (current != rhs.dummyTail) {
      out << current->data;
      if (current->next != rhs.dummyTail) {
          out << " ";
      }
      current = current->next;
  }
  return out;
}

void IntList::printReverse() const // prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space. This function does NOT output a new line or space at the end.
{
  IntNode *current = dummyTail->prev;
  while (current != dummyHead) {
      cout << current->data;
      if (current->prev != dummyHead) {
          cout << " ";
      }
      current = current->prev;
  }
}