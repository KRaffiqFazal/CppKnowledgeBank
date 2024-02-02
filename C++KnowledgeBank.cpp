#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Output.h"
#include "SinglyLinkedList.h"

// The purpose of this project will be to store implementations of all that I have learned within my algorithms
// and data structures module.

using namespace std;

int main()
{
  Output outputter;
  /*
  outputter.singleLine("single line of text");
  outputter.spaceTabber("each word tabbed.");
  outputter.wordLine("each word on new line.");
  outputter.chatterbox();
  */
  SinglyLinkedList* newList = new SinglyLinkedList("item 1");
  outputter.singleLine(newList->head->data);
  newList->pushStart("new item");
  outputter.singleLine(newList->head->data);
  newList->remove(0);
  outputter.singleLine(newList->head->data);

}