#pragma once
#include <string>

using namespace std;

class BBranch
{
  public:
    string data;
    BBranch* left;
    BBranch* right;

    BBranch(string valueToAddToBranch)
    {
      data = valueToAddToBranch;
    }
};

