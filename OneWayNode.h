#pragma once
#include <iostream>
using namespace std;
template <typename T>
class OneWayNode
{
public:
  T data;
  OneWayNode* next;

  OneWayNode(T dataToAdd)
  {
    data = dataToAdd;
    next = NULL;
  }
};

