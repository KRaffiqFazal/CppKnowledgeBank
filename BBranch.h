#pragma once
class BBranch
{
  public:
    int data;
    BBranch* left;
    BBranch* right;

    BBranch(int valueToAddToBranch)
    {
      data = valueToAddToBranch;
    }
};

