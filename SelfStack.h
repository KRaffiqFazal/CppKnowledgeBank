#pragma once
#include <iostream>
#include "OneWayNode.h"

template <typename T>
class SelfStack
{
public:
  OneWayNode<T>* top;

  SelfStack(T dataToAdd = NULL)
  {
    if (dataToAdd == NULL)
    {
      top = NULL;
    }
    else
    {
      top = new OneWayNode<T>(dataToAdd);
    }
  }

  void push(T dataToAdd)
  {
    OneWayNode<T>* newNode = new OneWayNode<T>(dataToAdd);
    if (top != NULL)
    {
      newNode->next = top;
    }
    top = newNode;
    return;
  }

  bool pop()
  {
    bool returnVal = false;
    if (top != NULL)
    {
      OneWayNode<T>* toDelete = top;
      top = top->next;
      delete toDelete;
      returnVal = true;
    }
    return returnVal;
  }

  bool empty()
  {
    bool empty = true;
    if (top != NULL)
    {
      empty = false;
    }
    return empty;
  }
};

