#pragma once
#include <string>

using namespace std;
class OneWayNode
{
public:
  string data;
  OneWayNode* next;

  OneWayNode(string dataToAdd)
  {
    data = dataToAdd;
  }
};

