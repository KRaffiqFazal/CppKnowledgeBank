#pragma once
#include <string>
#include <iostream>
using namespace std;
class Output
{
public:
  /// <summary>
  /// Outputs string as normal.
  /// </summary>
  /// <param name="data">To be outputted.</param>
  void singleLine(string data)
  {
    cout << data << endl;
  }
  /// <summary>
  /// Outputs each word in string with a tab instead of space.
  /// </summary>
  /// <param name="data">To be outputted.</param>
  void spaceTabber(string data)
  {
    for (char val : data)
    {
      if (val != ' ')
      {
        cout << val;
      }
      else
      {
        cout << "\t";
      }
    }
    cout << endl;
  }

  /// <summary>
  /// Outputs each word on new line.
  /// </summary>
  /// <param name="data">To be outputted.</param>
  void wordLine(string data)
  {
    for (char val : data)
    {
      if (val != ' ')
      {
        cout << val;
      }
      else
      {
        cout << "\n";
      }
    }
    cout << endl;
  }

  void chatterbox()
  {
    cout << "Enter Q to cancel\n\n" << endl << "User said: ";
    string input;
    getline(cin, input);

    while (input != "q")
    {
      cout << "\nChatterbox said: " << input << endl << "Enter Q to cancel." << "\n\n";
      cout << "User said: ";
      getline(cin, input);
    }
  }
};

