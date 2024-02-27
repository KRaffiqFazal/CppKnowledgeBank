#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Output.h"
#include "SinglyLinkedList.h"
#include "BTree.h"
#include "SelfStack.h"
#include <algorithm>
#include <vector>
#include "Sorting.h"

// The purpose of this project will be to store implementations of all that I have learned within my algorithms
// and data structures module.

using namespace std;

bool isNumber(string numberToCheck);
int Solve(BBranch* root);
string separateData(string expression);
double evaluatePostfix(string postfixExpression);

int main()
{
  /*cout << separateData("A1B2C3") << endl;

  cout << evaluatePostfix("5+10");

  BTree* expressionTree = new BTree("+");
  expressionTree->root->left = new BBranch("3");
  expressionTree->root->right = new BBranch("*");
  expressionTree->root->right->right = new BBranch("2");
  expressionTree->root->right->left = new BBranch("+");
  expressionTree->root->right->left->left = new BBranch("5");
  expressionTree->root->right->left->right = new BBranch("9");

  cout << Solve(expressionTree->root);*/

  vector<int> unsortedIntegers = { 3, 7, 12, 51, 42, 86, 99, -6, 21, 23, 0, 4, 3, 7 };
  unsortedIntegers = Sorting::mergeSortAsc(unsortedIntegers);

  for (int item : unsortedIntegers)
  {
    cout << item << endl;
  }
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

string separateData(string expression)
{
  SelfStack<char>* numbers = new SelfStack<char>();
  SelfStack<char>* finalStack = new SelfStack<char>();
  string finalExpression;

  for (char val : expression)
  {
    if (isdigit(val))
    {
      numbers->push(val);
    }
    else
    {
      finalExpression += val;
    }
  }

  while (!numbers->empty())
  {
    finalStack->push(numbers->top->data);
    numbers->pop();
  }
  
  while (!finalStack->empty())
  {
    finalExpression += finalStack->top->data;
    finalStack->pop();
  }

  return finalExpression;
}

double basicEvaluation(double val1, double val2, char operatorUsed)
{
  double expression = 0;
  if (operatorUsed == '+')
  {
    expression = val1 + val2;
  }
  else if (operatorUsed == '-')
  {
    expression = val1 - val2;
  }
  else if (operatorUsed == '*')
  {
    expression = val1 * val2;
  }
  else if (operatorUsed == '/')
  {
    expression = val1 / val2;
  }
  return expression;
}
double evaluatePostfix(string postfixExpression)
{
  reverse(postfixExpression.begin(), postfixExpression.end());
  string number = "";
  SelfStack<double>* operands = new SelfStack<double>();
  SelfStack<char>* operators = new SelfStack<char>();
  double operand1;
  double operand2;

  for (char val : postfixExpression)
  {
    if (!isdigit(val))
    {
      if (number != "")
      {
        operands->push(stoi(number));
        number = "";
      }
      operators->push(val);
    }
    else
    {
      number = val + number;
    }
  }
  if (number != "")
  {
    operands->push(stoi(number));
  }

  while (!operators->empty())
  {
    operand1 = operands->top->data;
    operands->pop();
    operand2 = operands->top->data;
    operands->pop();

    operands->push(basicEvaluation(operand1, operand2, operators->top->data));
    operators->pop();
  }
  return operands->top->data;
}

