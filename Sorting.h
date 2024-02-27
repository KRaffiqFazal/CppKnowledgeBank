#pragma once
#include <vector>

using namespace std;

class Sorting
{
public:

  static vector<int> bubbleSortAsc(vector<int> unsortedVector)
  {
    bool swap = false;
    int temp;
    for (int i = 0; i < unsortedVector.capacity() - 1; i++)
    {
      swap = false;
      for (int j = 0; j < unsortedVector.capacity() - i - 1; j++)
      {
        if (unsortedVector[j] >= unsortedVector[j + 1])
        {
          swap = true;
          temp = unsortedVector[j];
          unsortedVector[j] = unsortedVector[j + 1];
          unsortedVector[j + 1] = temp;
        }
      }
      if (!swap)
      {
        break;
      }
    }
    return unsortedVector;
  }

  static vector<int> mergeSortAsc(vector<int> toSort)
  {
    if (toSort.capacity() <= 1)
    {
      return toSort;
    }
    size_t middle = toSort.capacity() / 2;
    vector<int> left(toSort.begin(), toSort.begin() + middle);
    vector<int> right(toSort.begin() + middle, toSort.end());

    left = mergeSortAsc(left);
    right = mergeSortAsc(right);

    return merge(left, right);
  }

private:
  static vector<int> merge(vector<int> toMergeLeft, vector<int> toMergeRight)
  {
    vector<int> merged;

    size_t leftIndex = 0;
    size_t rightIndex = 0;

    while (leftIndex < toMergeLeft.capacity() && rightIndex < toMergeRight.capacity())
    {
      if (toMergeLeft[leftIndex] <= toMergeRight[rightIndex])
      {
        merged.push_back(toMergeLeft[leftIndex]);
        leftIndex++;
      }
      else
      {
        merged.push_back(toMergeRight[rightIndex]);
        rightIndex++;
      }
    }

    while (leftIndex < toMergeLeft.capacity())
    {
      merged.push_back(toMergeLeft[leftIndex]);
      leftIndex++;
    }

    while (rightIndex < toMergeRight.capacity())
    {
      merged.push_back(toMergeRight[rightIndex]);
      rightIndex++;
    }

    return merged;
  }
};

