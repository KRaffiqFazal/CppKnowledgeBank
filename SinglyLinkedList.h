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
    OneWayNode* tempAdder;
    while (counter <= indexToInsert && position != NULL)
    {
      if (indexToInsert == counter)
      {
        tempAdder->next = position;
        tempAdder->data = data;
        
        if (counter == 0)
        {
          head = tempAdder;
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
    int counter = 0;
    OneWayNode* position = head;
    OneWayNode* previousNode = NULL;
    
    while (counter <= indexToDelete && position != NULL)
    {
      if (counter == indexToDelete)
      {
        if (previousNode == NULL)
        {
          head = position->next;
          delete position;
        }
        else
        {
          previousNode->next = position->next;
          delete position;
        }
      }
      previousNode = position;
      position = position->next;
    }
  }
};

