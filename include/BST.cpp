// BST.cpp
// A node-based binary search tree (BST) class, supplemented with additional variables and methods for improved functionality.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <iostream>
#include <string>

using namespace std;

#ifndef BST_CPP
#define BST_CPP

template <class E>
class TreeNode
{
    public:

      TreeNode(); //default constructor
      TreeNode(const TreeNode<E> &T1);
      TreeNode (E k); //overloaded constructor
      virtual ~TreeNode();
      //Other Functions that will be useful to us
        //Equality operators to compare the values of tree nodes
      void operator=(const TreeNode<E> &T1);
      bool operator==(const TreeNode<E> &T1);
      //Member Variables
      E key;
      TreeNode<E> *left;
      TreeNode<E> *right;
};

template <class E>
TreeNode<E>::TreeNode()
{
    left = NULL;
    right = NULL;
}

template <class E>
TreeNode<E>::TreeNode(const TreeNode<E> &T1)
{
  left = NULL;
  right = NULL;
  key = T1->key;
}


template <class E>
TreeNode<E>::TreeNode(E k)
{
    left = NULL;
    right = NULL;
    key = k;
}

template <class E>
TreeNode<E>::~TreeNode()
{

}

//Used to copy one node to another via values. Pointers are nulled out for simplicity
template <class E>
void TreeNode<E>::operator=(const TreeNode<E> &T1)
{
  left = NULL;
  right = NULL;
  key = T1->key;
}

//Used to tell whether two nodes are equal based on key values
template <class E>
bool TreeNode<E>::operator==(const TreeNode<E> &T1)
{
  return (key == T1.key);
}

template <class E>
class BST
{
    public:
        BST(); //default constructor
        virtual ~BST(); // destructor
        void destroyRecursive(TreeNode<E> *node);
        void copy(const BST<E>& B1);
        void operator=(const BST<E>& B1);
        void clear(); //a method used to wipe a BST clean
        void insert(E value); //value is the key
        bool contains(E value); //AKA search
        bool deleteNode(E value); //true if node was deleted successfully, false if not
        TreeNode<E>* getSuccessor(TreeNode<E>* d); //getting the successor of a deletion. Used in deleteNode
        bool isEmpty() const; //returns true if the tree is empty
        void printTree(); //prints the entire Tree
        void recPrint(TreeNode<E> *node); //recursive method that prints a subtree rooted at the node in the function
        //I am going to add some other functions to make my class more functional for this case
        TreeNode<E>* getRoot() const; // this will be used to get the root of tree. It will be helpful when we want to copy trees over
        TreeNode<E>* getNode(E value); // a function that retrieves a node in the tree via searching for it. Very useful
        int getSize();  //an accessor that will help us determine whether a BST has a certain number of elements in it
    private:
        TreeNode<E> *root;
        void recCopy(const TreeNode<E> *node); //a recursive copy method for tree nodes. This will be used to copy trees over
        int m_size; //A variable that keeps track of the size of a BST.
        friend class TreeNode<E>;
};

template <class E>
BST<E>::BST() //default constructor
{
    root = NULL; //empty tree
    int m_size = 0;
}

template <class E>
BST<E>::~BST()
{
    destroyRecursive(root);
}

template <class E>
void BST<E>::destroyRecursive(TreeNode<E> *node)
{
  if(node == NULL)
  {
    return; //ends function
  }

  destroyRecursive(node->left);
  delete node;
  destroyRecursive(node->right);
}

//The copy method first destroys a tree and then copies another tree from its root
template <class E>
void BST<E>::copy(const BST<E>& B1)
{
  destroyRecursive(root);
  recCopy(B1.getRoot());
}

template <class E>
void BST<E>::operator=(const BST<E>& B1)
{
  copy(B1);
}

template <class E>
void BST<E>::clear()
{
  destroyRecursive(root);
  root = NULL; //empty tree
  m_size = 0;
}

template <class E>
void BST<E>::printTree()
{
    recPrint(root);
}

template <class E>
void BST<E>::recPrint(TreeNode<E> *node)
{
    if(node == NULL)
    {
        return; //ends function
    }

    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template <class E>
bool BST<E>::isEmpty() const
{
    return (root == NULL);
}

template <class E>
void BST<E>::insert(E value)
{
    //check if value exist, if not continue

    TreeNode<E> *node = new TreeNode<E>(value); //key is now set to value

    if(isEmpty()) //empty Tree
    {
      root = node;
      m_size++;
    }

    else //not an empty tree, need to find insertion point
    {
        TreeNode<E> *current = root;
        TreeNode<E> *parent; //empty node

        while(true)
        {
            parent = current;

            if(value < current->key)
            {
                current = current->left; //going left

                if(current==NULL) //we found a home for our new node
                {
                    parent->left = node;
                    break;
                }
                //else keep looping
            }

            else if(value == current->key)
            {
              break; //we have found the node, so we don't need to insert it again
            }

            else
            {
                current = current->right;

                if(current == NULL) //we found a home for our new node
                {
                    parent->right = node;
                    break;
                }
            }
        }
      m_size++;
    }
}

template <class E>
bool BST<E>::contains(E value)
{
    if(isEmpty())
    {
        return false;
    }

    else //not an empty tree
    {
        TreeNode<E> *current = root;

        while(current->key != value)
        {
            if(value < current->key) //go left
                current = current->left;
            else
                current = current->right;
            if(current == NULL)
                return false;
        }
    }
    return true;
}

template <class E>
bool BST<E>::deleteNode(E value)
{
  if(isEmpty())
  {
      return false;
  }
  else if(!(contains(value)))
  {
    return false;
  }
  else
  {
      TreeNode<E> *current = root;
      TreeNode<E> *parent = root;
      bool isLeft = true;
      while (current->key != value)
      {
        parent = current;
        if (value < current->key)
        {
          isLeft = true;
          current = current->left;
        }
        else
        {
          isLeft = false;
          current = current->right;
        }
        if(current==NULL)
        {
          return false;
        }
      }
      //we found our node
      //now let's check our cases

      if (current->left == NULL && current->right == NULL)
      {
        //check if we only have the root
        if (current == root)
        {
          root = NULL;
        }
        else if (isLeft)
        {
          parent->left = NULL;
        }
        else //right child
        {
          parent->right = NULL;
        }
      }
      //check for one child - both left and right
      else if (current->right == NULL) // no right child
      {
        if(current == root)
        {
          root = current->left;
        }
        else if (isLeft)
        {
          parent->left = current->left;
          current->left = NULL;
        }
        else
        {
          parent->right = current->left;
          current->left = NULL;
        }
      }
      else if (current->left == NULL) // no left child
      {
        if(current == root)
        {
          root = current->right;
        }
        else if (isLeft)
        {
          parent->left = current->right;
          current->right = NULL;
        }
        else
        {
          parent->right = current->right;
          current->right = NULL;
        }
      }
      else // the node has two children
      {
        TreeNode<E> *successor = getSuccessor(current);

        if (current==root)
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
        {
          parent->right = successor;
        }

        successor->left = current->left;
      }
      m_size--;
      return true;
  }
}

template <class E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* d) // d is the node to be deleted
{
  TreeNode<E> *sp = d; // successor's parent
  TreeNode<E> *successor = d;
  // what should this be? previously said TreeNode *current->d->right;
  TreeNode<E> *current = d->right;
  // while loop is all about rearranging pointers
  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  //extra things to do
  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

template <class E>
TreeNode<E>* BST<E>::getRoot() const
{
  if(isEmpty())
  {
      return NULL;
  }
  return root;
}

template <class E>
TreeNode<E>* BST<E>::getNode(E value)
{
  if(isEmpty())
  {
      return NULL;
  }
  else if(!(contains(value)))
  {
    return NULL;
  }
  else
  {
    TreeNode<E> *current = root;
    TreeNode<E> *parent = root;
    bool isLeft = true;
    while (current->key != value)
    {
      parent = current;
      if (value < current->key)
      {
        isLeft = true;
        current = current->left;
      }
      else
      {
        isLeft = false;
        current = current->right;
      }
      if(current==NULL)
      {
        return NULL;
      }
    }
    return current;
  }
}

//A method I made myself! :) It 'copies' a tree by inserting all the nodes that that tree has.
template <class E>
void BST<E>::recCopy(const TreeNode<E> *node)
{
  if(node == NULL)
  {
      return; //ends function
  }
  recCopy(node->left);
  insert(node->key);
  recCopy(node->right);
}

template <class E>
int BST<E>::getSize()
{
  return m_size;
}

#endif
