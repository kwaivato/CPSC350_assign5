// DoublyList.cpp
// A node-based doubly-linked list class, supplemented with additional variables and methods for improved functionality.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <iostream>
#include <string>
#include "ListEmpty.cpp"

using namespace std;

#ifndef DoublyList_CPP
#define DoublyList_CPP

//Doubly LinkedList Node Interface
template <class E>
class DoublyListNode
{
  public:
    DoublyListNode();
    DoublyListNode(const E e);
    ~DoublyListNode();
    E m_data;
    DoublyListNode<E> *next;
    DoublyListNode<E> *prev;
  private:
};

//Doubly LinkedList Node Implementation
template <class E>
DoublyListNode<E>::DoublyListNode()
{
  next = NULL;
  prev = NULL;
}

template <class E>
DoublyListNode<E>::DoublyListNode(const E e)
{
  m_data = e;
  next = NULL;
  prev = NULL;
}

template <class E>
DoublyListNode<E>::~DoublyListNode()
{

}

//Doubly LinkedList Interface
template <class E>
class DoublyList
{
  public:
    DoublyList();
    ~DoublyList();
    void insertFront(const E e);
    void insertBack(const E e);
    E seeFront() throw (ListEmpty);
    E removeFront() throw (ListEmpty);
    E removeBack() throw (ListEmpty);
    void deletePosition(int pos) throw (ListEmpty);
    void printList() throw (ListEmpty);
    int find(const E e) throw (ListEmpty);
    void remove(const E e) throw (ListEmpty);
    bool isEmpty() const;
    bool contains(const E e) throw (ListEmpty);
    unsigned int getSize();
    DoublyListNode<E>* getFront() const throw (ListEmpty); //extra method that makes it easier to access list elements
  private:
    DoublyListNode<E> *m_front;
    DoublyListNode<E> *m_back;
    unsigned int m_size;
};

//Doubly LinkedList Implementation
template <class E>
DoublyList<E>::DoublyList()
{
  m_front = NULL;
  m_back = NULL;
  m_size = 0;
}

template <class E>
DoublyList<E>::~DoublyList()
{
  if (m_front == NULL)
  {
    delete m_front;
  }
  else
  {
    while (m_front->next != NULL)
    {
      DoublyListNode<E> *nextNode = m_front->next;
  		m_front->next = nextNode->next;
  		delete nextNode;
    }
    delete m_front;
  }
}

template <class E>
void DoublyList<E>::insertFront(const E e)
{
  DoublyListNode<E> *node = new DoublyListNode<E>(e);
  if (m_size == 0)
  {
    m_back = node;
  }
  else
  {
    m_front->prev = node;
    node->next = m_front;
  }
  m_front = node;
  ++m_size;
}

template <class E>
void DoublyList<E>::insertBack(const E e)
{
  DoublyListNode<E> *node = new DoublyListNode<E>(e);
  if (m_size == 0)
  {
    m_front = node;
  }
  else
  {
    m_back->next = node;
    node->prev = m_back;
  }
  m_back = node;
  ++m_size;
}

template <class E>
E DoublyList<E>::seeFront() throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  return m_front->m_data;
}

template <class E>
E DoublyList<E>::removeFront() throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  E& temp = m_front->m_data;
  DoublyListNode<E> *ft = m_front;
  m_front = m_front->next;
  if (m_front != NULL)
  {
    m_front->prev = NULL;
    ft->next = NULL;
  }
  else
  {
    m_back = NULL;
  }
  delete ft;
  --m_size;
  return temp;
}

template <class E>
E DoublyList<E>::removeBack() throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  E& temp = m_back->m_data;
  DoublyListNode<E> *bk = m_back;
  m_back = m_back->prev;
  if (m_back != NULL)
  {
    m_back->next = NULL;
    bk->prev = NULL;
  }
  else
  {
    m_front = NULL;
  }
  delete bk;
  --m_size;
  return temp;
}

template <class E>
void DoublyList<E>::deletePosition(int pos) throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  if(pos == -1)
  {
    cout << "The element you're trying to remove is not in this list." << endl;
  }
  else if (pos > m_size - 1)
  {
    cout << "Out of Range Deletion Position!" << endl;
  }
  else
  {
    int idx = 0;
    DoublyListNode<E> *curr = m_front;
    DoublyListNode<E> *prev = m_front;

    while(idx != pos)
    {
      prev = curr;
      curr = curr->next;
      ++idx;
    }
    // four cases
    if (curr == m_front && curr == m_back)
    {
      m_front = NULL;
      m_back = NULL;
    }
    else if (curr == m_front && curr != m_back)
    {
      m_front = curr->next;
      m_front->prev = NULL;
      curr->next = NULL;
    }
    else if (curr != m_front && curr == m_back)
    {
      m_back = curr->prev;
      m_back->next = NULL;
      curr->prev = NULL;
    }
    else
    {
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
      curr->next = NULL;
      curr->prev = NULL;
    }
    E& temp = curr->m_data;
    delete curr;
    m_size--;
  }
}

template <class E>
void DoublyList<E>::printList() throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to print.");
  }
  DoublyListNode<E> *curr = m_front;
  while ((curr->next) != NULL && curr!= m_back)
  {
    cout << (curr->m_data) << ", ";
    curr = curr->next;
  }
  cout << (curr->m_data) << endl;
}

template <class E>
int DoublyList<E>::find(const E e) throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to look for.");
  }
  int idx = -1;
  DoublyListNode<E> *curr = m_front;
  while ((curr->next != NULL))
  {
    ++idx;
    if (curr->m_data == e)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if(curr == m_front && curr->m_data == e)
  {
    idx = 0;
  }
  else if(curr == m_back && curr->m_data == e)
  {
    idx = m_size - 1;
  }
  else if(curr->next == NULL)
  {
    idx = -1;
  }

  return idx;
}

template <class E>
void DoublyList<E>::remove(const E e) throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  int pos = find(e);
  deletePosition(pos);
}

template <class E>
bool DoublyList<E>::isEmpty() const
{
  if (m_front == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class E>
bool DoublyList<E>::contains(const E e) throw (ListEmpty)
{
  if(isEmpty())
  {
    throw ListEmpty("Your list is empty! No elements to look for.");
  }
  int x = find(e);
  if (x == -1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

template <class E>
unsigned int DoublyList<E>::getSize()
{
  return m_size;
}

//Returns a pointer to the front of the list, which can be used to update other elements of the list by updating curr = curr->next
template <class E>
DoublyListNode<E>* DoublyList<E>::getFront() const throw (ListEmpty)
{
  if(isEmpty() == true)
  {
    return NULL;
    throw ListEmpty("Your list is empty! No elements to remove.");
  }
  else
  {
    return m_front;
  }
}

#endif
