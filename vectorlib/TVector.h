#pragma once
#include <iostream>
#include "exception.h"
template <class T>
class TVector
{
protected:
	int l; //lenght
	T* p; //pointer
  int pos;//position
public:
	TVector();
	TVector(int n, int _pos);
  TVector(int n);
	TVector(const TVector<T>& A);
	~TVector();
	int GetSize() const; //return lenght
  int GetPos() const;
	bool operator != (const TVector<T>& A);
  bool operator == (const TVector<T>& A);
  TVector<T>& operator = (const TVector<T> &A);
  T& GetValue(int i) const;
	T& operator [](int i) const;
	TVector<T> operator + (const TVector<T> &A);
	TVector<T> operator - (const TVector<T>& A);
	TVector<T> operator * (const TVector<T> &A);
	TVector<T> operator + (const T& k);
	TVector<T> operator - (const T& k);
	TVector<T> operator * (const T& k);

  friend std::istream &operator>>(std::istream &in, TVector<T> &A)
  {
    for (int i = 0; i < A.l; i++)
      in >> A.GetValue(i);
    return in;
  }

  friend std::ostream &operator<<(std::ostream &out,const TVector<T> &A)
  {
    for (int i = 0; i < A.l; i++)
      out << A.GetValue(i) << ' ';
    return out;
  }
};

template <class T>
TVector<T>::TVector()
{
  l = 0;
  p = NULL;
  pos = 0;
}



template <class T>
TVector<T>::TVector(int n, int _pos)
{
	if (n < 0)
		throw(__NEG_SIZE);
	else if (n == 0)
  {
    l = 0;
    p = NULL;
    pos = 0;
  } 
  else
	{
		l = n;
		p = new T[l];
    for (int i = 0; i < l; i++)
      p[i] = (T)0;
    pos = _pos;
	}
}

template <class T>
TVector<T>::TVector(int n)
{
  if (n < 0)
    throw(__NEG_SIZE);
  else if (n == 0)
  {
    l = 0;
    p = NULL;
    pos = 0;
  }
  else
  {
    l = n;
    p = new T[l];
    for (int i = 0; i < l; i++)
      p[i] = (T)0;
    pos = 0;
  }
}

template <class T>
TVector<T>::TVector(const TVector<T>& A)
{
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];
  pos = A.pos;
}

template <class T>
TVector<T>::~TVector()
{ 
  if(p != NULL)
	  delete[] p;
}

template <class T>
int TVector<T>::GetSize() const
{
	return l;
}

template<class T>
int TVector<T>::GetPos() const
{
  return pos;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& A)
{
  if(p != NULL)
    delete[] p;
  l = A.l;
  p = new T[l];
  pos = A.pos;
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template<class T>
T & TVector<T>::GetValue(int i) const
{
  if (i >= l || i  < 0)
    throw(__IND_IS_OUT_OF_RANGE);
  else
    return p[i];
}

template<class T>
bool TVector<T>::operator == (const TVector<T>& A)
{
	if (l != A.l)
		return false;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return false;
	return true;
}

template<class T>
bool TVector<T>::operator!=(const TVector<T>& A)
{
	if (l != A.l)
		return true;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return true;
	return false;
}

template<class T>//pos?
T& TVector<T>::operator[](int i) const
{
	if (i - pos>= l || i -pos < 0)
		throw(__IND_IS_OUT_OF_RANGE);
	else
		return p[i - pos];
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + A.p[i];
	return R;
}


template<class T>
TVector<T> TVector<T>::operator-(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator+(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * k;
	return R;
}

