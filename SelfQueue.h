#pragma once
#include <string>
#include "TwoWayNode.h"
class SelfQueue
{
  public:
    TwoWayNode* head;
    TwoWayNode* tail;

    SelfQueue(int dataToAdd)
    {
      head = new TwoWayNode(dataToAdd);
      tail = head;
    }

    void enqueue(int dataToAdd)
    {
      TwoWayNode* newNode = new TwoWayNode(dataToAdd);
      tail->next = newNode;
      newNode->previous = tail;
      tail = newNode;
      return;
    }

    void deleteNode()
    {
      TwoWayNode* toDelete = head;
      head = head->next;
      delete toDelete;
      return;
    }
};

