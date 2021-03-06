#pragma once
#include "Stack.h"

template <class T>
class TQueue : public TStack<T>
{  
private:
  int st;
public:
  TQueue(int n);
  TQueue(TQueue<T>& A);
  void Put(const T s);
  T Get();
  T Check();
};

template<class T>
TQueue<T>::TQueue(int n):TStack<T>(n)
{
  st = 0;
}

template<class T>
TQueue<T>::TQueue(TQueue<T>& A):TStack<T>(A)
{
  st = A.st;
}

template<class T>
void TQueue<T>::Put(const T s)
{
  if (this->IsFull())
    throw(__SOD_IS_FULL);

  if (this->size > st + this->pos)
    this->p[st + this->pos] = s;
  else
    this->p[st + this->pos - this->size] = s;

  this->pos++;
}

template<class T>
T TQueue<T>::Get()
{
  if (this->IsEmpty())
    throw(__SOD_IS_EMPTY);

  T temp = this->p[st++];

  this->pos--;

  if (st == this->size)
    st = 0;

  return temp;
}

template<class T>
T TQueue<T>::Check()
{
  if (this->IsEmpty())
    throw(__SOD_IS_EMPTY);

  return this->p[st];
}
