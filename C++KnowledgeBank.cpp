#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Output.h"
#include "SinglyLinkedList.h"
#include "BTree.h"

// The purpose of this project will be to store implementations of all that I have learned within my algorithms
// and data structures module.

using namespace std;

bool isNumber(string numberToCheck);
int Solve(BBranch* root);

int main()
{
  BTree* expressionTree = new BTree("+");
  expressionTree->root->left = new BBranch("3");
  expressionTree->root->right = new BBranch("*");
  expressionTree->root->right->right = new BBranch("2");
  expressionTree->root->right->left = new BBranch("+");
  expressionTree->root->right->left->left = new BBranch("5");
  expressionTree->root->right->left->right = new BBranch("9");

  cout << Solve(expressionTree->root);
}

int NewValue(int operand1, int operand2, string newOperator)
{
  if (newOperator == "+")
  {
    return operand1 + operand2;
  }
  else if (newOperator == "-")
  {
    return operand1 - operand2;
  }
  else if (newOperator == "*")
  {
    return operand1 * operand2;
  }
  else if (newOperator == "/")
  {
    return operand1 / operand2;
  }
  else
  {
    return 0;
  }
}

int Solve(BBranch* root)
{
  if (isNumber(root->left->data) && isNumber(root->right->data))
  {
    int val1 = stoi(root->left->data);
    int val2 = stoi(root->right->data);
    return NewValue(val1, val2, root->data);
  }
  else if (isNumber(root->left->data))
  {
    int val1 = stoi(root->left->data);
    return NewValue(val1, Solve(root->right), root->data);
  }
  else
  {
    int val2 = stoi(root->right->data);
    return NewValue(Solve(root->left), val2, root->data);
  }
}

bool isNumber(string numberToCheck)
{
  for (char val : numberToCheck)
  {
    if (!isdigit(val))
    {
      return false;
    }
  }
  return true;
}