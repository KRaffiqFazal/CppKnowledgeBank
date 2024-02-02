#pragma once
#include <string>
#include "OneWayNode.h"

using namespace std;
class SinglyLinkedList
{
public:
  OneWayNode* head;

  /// <summary>
  /// Creates a new singly linked list.
  /// </summary>
  /// <param name="data">Data to be held as the first item.</param>
  SinglyLinkedList(string data)
  {
    head = new OneWayNode(data);
    head->next = NULL;
  }

  /// <summary>
  /// Pushes new data item to the start of the linked list.
  /// </summary>
  /// <param name="data">Data to be added.</param>
  void pushStart(string data)
  {
    insert(data, 0);
  }

  /// <summary>
  /// Inserts new item at given index.
  /// </summary>
  /// <param name="data">Data to be inserted.</param>
  /// <param name="indexToInsert">Position to be inserted into.</param>
  void insert(string data, int indexToInsert)
  {
    int counter = 0;
    OneWayNode* position = head;
    OneWayNode* tempAdder = new OneWayNode(data);
    while (counter <= indexToInsert && position != NULL)
    {
      if (indexToInsert == counter)
      { 
        if (counter == 0)
        {
          tempAdder->next = head;
          head = tempAdder;
        }
        else
        {
          tempAdder->next = position->next;
          position->next = tempAdder;
        }
      }
      position = position->next;
      counter++;
    }
  }

  /// <summary>
  /// Removes item from given index in the linked list.
  /// </summary>
  /// <param name="indexToDelete">Index to delete item from in list.</param>
  void remove(int indexToDelete)
  {
    int counter = 1;
    OneWayNode* position = head;
    OneWayNode* nextNode = head->next;
    if (indexToDelete == 0)
    {
      head = nextNode;
      delete position;
      return;
    }
    while (counter <= indexToDelete && position != NULL)
    {
      if (counter == indexToDelete)
      {
        position->next = nextNode->next;
        delete nextNode;
      }
      counter++;
      nextNode = nextNode->next;
      position = position->next;
    }
  }
};

