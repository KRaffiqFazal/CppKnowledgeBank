#pragma once
#include <string>

using namespace std;
class TwoWayNode
{
public:
  string data;
  TwoWayNode* previous;
  TwoWayNode* next;

  TwoWayNode(string dataToAdd)
  {
    data = dataToAdd;
  }
};

