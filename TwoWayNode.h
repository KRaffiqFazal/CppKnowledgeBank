#pragma once

using namespace std;
class TwoWayNode
{
public:
  int data;
  TwoWayNode* previous;
  TwoWayNode* next;

  TwoWayNode(int dataToAdd)
  {
    data = dataToAdd;
  }
};

