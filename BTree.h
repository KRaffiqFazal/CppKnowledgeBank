#pragma once
#include "BBranch.h"
#include "SelfQueue.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class BTree
{
  private:
    vector<int> specifiedTraversal;

  public:
    BBranch* root;
    
    BTree(int rootValue)
    {
      root = new BBranch(rootValue);
    }

    int size(BBranch* currentTraversedNode)
    {
      if (currentTraversedNode == NULL)
      {
        return 0;
      }
      else
      {
        return size(currentTraversedNode->left) + size(currentTraversedNode->right) + 1;
      }
    }

    int depth(BBranch* currentTraversedNode)
    {
      if (currentTraversedNode == NULL)
      {
        return 1;
      }
      else
      {
        return 1 + max(depth(currentTraversedNode->left), depth(currentTraversedNode->right));
      }
    }

    vector<int> preOrderReturner(BBranch* branch, string option)
    {
      specifiedTraversal.clear();
      if (option == "pre-order")
      {
        preOrderTraversal(branch);
      }
      else if (option == "in-order")
      {
        inOrderTraversal(branch);
      }
      else if (option == "post-order")
      {
        postOrderTraversal(branch);
      }
      else if (option == "level-order")
      {
        levelOrderTraversal(branch);
      }
      return specifiedTraversal;
    }

    void preOrderTraversal(BBranch* branch)
    {
      if (branch == NULL)
      {
        return;
      }

      specifiedTraversal.push_back(branch->data);
      preOrderTraversal(branch->left);
      preOrderTraversal(branch->right);
    }

    void inOrderTraversal(BBranch* branch)
    {
      if (branch == NULL)
      {
        return;
      }

      inOrderTraversal(branch->left);
      specifiedTraversal.push_back(branch->data);
      inOrderTraversal(branch->right);
    }

    void postOrderTraversal(BBranch* branch)
    {
      if (branch == NULL)
      {
        return;
      }

      postOrderTraversal(branch->left);
      postOrderTraversal(branch->right);
      specifiedTraversal.push_back(branch->data);
    }

    void levelOrderTraversal(BBranch* branch)
    {
      if (branch == NULL)
      {
        return;
      }

      queue<BBranch*> queue;
      queue.push(branch);
      

      while (!queue.empty())
      {
        BBranch* current = queue.front();
        queue.pop();
        specifiedTraversal.push_back(branch->data);

        if (branch->left != NULL)
        {
          queue.push(current->left);
        }
        if (current->right != NULL)
        {
          queue.push(current->right);
        }
      }
    }
};

