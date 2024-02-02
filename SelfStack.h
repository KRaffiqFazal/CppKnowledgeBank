#pragma once
#include <string>
#include "OneWayNode.h"
class SelfStack
{
public:
  OneWayNode* top;

  SelfStack(string dataToAdd)
  {
    top = new OneWayNode(dataToAdd);
  }

  void push(string dataToAdd)
  {
    OneWayNode* newNode = new OneWayNode(dataToAdd);
    newNode->next = top;
    top = newNode;
    return;
  }

  void pop()
  {
    OneWayNode* toDelete = top;
    top = top->next;
    delete toDelete;
    return;
  } 
};

