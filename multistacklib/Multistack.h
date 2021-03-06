#pragma once
#include "MStack.h"

template <class T>
class TMulStack 
{
protected:
  int count;
  int l;
  MStack<T>** stacks;
  T* gstack;
  T** ind;
  int* lenS;
  bool Resize(int i);
  int resizeCount;
public:
  TMulStack(int _count, int _l);
  TMulStack(const TMulStack& A);
  ~TMulStack();
  void Put(T a, int _i);
  T Get(int i);
  int GetSize(int i);
  bool IsEmpty(int _i);
  bool IsFull(int _i);
  int CalcFree();
};

template<class T>
int TMulStack<T>::CalcFree()
{
	int res = 0;
	for(int i = 0; i < count; i++)
		res += (stacks[i]->GetSize() - stacks[i]->GetCount());
	return res;
}

template<class T>
bool TMulStack<T>::Resize(int _i)
{
	int in, j, k, n;
	int FreeMemSize = CalcFree();

	if (FreeMemSize == 0)
		return false;

	resizeCount++;
	ind[0] = gstack;
	for (int i = 1; i < count; i++)
	{
		if (_i + 1 == i)
			ind[i] = ind[i - 1] + stacks[i - 1]->GetCount() + FreeMemSize / count + FreeMemSize % count;
		else
			ind[i] = ind[i - 1] + stacks[i - 1]->GetCount() + FreeMemSize / count;
	}

	for (in = 0; in < count; in++)
		if (ind[in] < stacks[in]->GetMem())
		{
			for (j = 0; j < stacks[in]->GetCount(); j++)
				ind[in][j] = (stacks[in]->GetMem())[j];
			stacks[in]->SetMem(ind[in], ind[in + 1] - ind[in]);
		}
		else if (ind[in] > stacks[in]->GetMem())
		{
			k = in;
			if (k < count - 1)
				for (k; ind[k + 1] > stacks[k + 1]->GetMem(); k++)
					if (k == count - 2)
						break;
			for (n = k; n >= in; n--)
			{
				for (j = stacks[n]->GetCount() - 1; j >= 0; j--)
					ind[n][j] = (stacks[n]->GetMem())[j];
				stacks[n]->SetMem(ind[n], ind[n + 1] - ind[n]);
			}
		}
		else
			stacks[in]->SetMem(ind[in], ind[in + 1] - ind[in]);
	for (int i = 0; i < count - 1; i++)
	{
		stacks[i]->SetLen(ind[i + 1] - ind[i]);
		lenS[i] = stacks[i]->GetSize();
	}
	stacks[count - 1]->SetLen((gstack + l) - ind[count - 1]);
	lenS[count - 1] = stacks[count - 1]->GetSize();


	return true;
  /*for (int i = 0; i < count; i++)
  {
    if (CalcFree(i) > 0)
    {
      if(i < _i)
      { 
        stacks[i]->SetMem(ind[i], --lenS[i]);
        for (int j = i + 1; j < _i; j++)
          stacks[j]->SetMem(--ind[j], lenS[j]);

        stacks[_i]->SetMem(--ind[_i], ++lenS[_i]);

        for (int k = ind[i + 1] - &gstack[0]; k < ind[_i + 1] - 1 - &gstack[0]; k++)
          gstack[k] = gstack[k + 1];
      }
      else
      {
        stacks[i]->SetMem(++ind[i], --lenS[i]);

        for (int j = _i + 1; j < i; j++)
          stacks[j]->SetMem(++ind[j], lenS[j]);

        stacks[_i]->SetMem(ind[_i], ++lenS[_i]);

        for (int k = ind[i] - &gstack[0] + lenS[i] - 1; k >= ind[_i + 1] - &gstack[0]; k--)
          gstack[k] = gstack[k - 1];
      }
      return true;
    }
  }
  return false;*/
	
}

template<class T>
TMulStack<T>::TMulStack(int _count, int _l)
{
  if (_count < 0 || _l < 0)
    throw(__NEG_SIZE);

  if(_count > _l)
    throw(__INVALID_SIZE_CTL);

  int resizeCount = 0;  
  count = _count;
  l = _l;
  gstack = new T[l];

  //length of all stacks
  lenS = new int[count]; 
  for (int i = 0; i < count; i++)
    lenS[i] = l / count;
  lenS[0] += l % count;

  //index for all stacks
  ind = new T*[count];
  ind[0] = gstack;
  int t = 0;
  for (int i = 1; i < count; i++)
  {
    ind[i] = &gstack[lenS[i - 1] + t];
    t += lenS[i - 1];
  }

  //set index and length for all stacks
  stacks = new MStack<T>*[count];
  for (int i = 0; i < count; i++)
  {
    stacks[i] = new MStack<T>();
    stacks[i]->SetMem(ind[i], lenS[i]);
  }
}

template<class T>
TMulStack<T>::TMulStack(const TMulStack& A)
{
  int resizeCount = 0;
  count = A.count;
  l = A.l;
  gstack = new T[l];

  lenS = new int[count];
  for (int i = 0; i < count; i++)
    lenS[i] = A.lenS[i];

  ind = new T*[count];
  ind[0] = gstack;
  int t = 0;
  for (int i = 1; i < count; i++)
  {
    ind[i] = &gstack[lenS[i - 1] + t];
    t += lenS[i - 1];
  }

  stacks = new MStack<T>*[count];
  for (int i = 0; i < count; i++)
  {
    stacks[i] = new MStack<T>();
    stacks[i]->SetMem(ind[i], lenS[i]);
    stacks[i]->SetPos(A.stacks[i]->GetCount());
  }

  for (int i = 0; i < l; i++)
    gstack[i] = A.gstack[i];
}

template<class T>
TMulStack<T>::~TMulStack()
{
  delete[] gstack;
  delete[] ind;
  delete[] lenS;
}

template<class T>
void TMulStack<T>::Put(T a, int _i)
{
  if (IsFull(_i) == true)
    if (Resize(_i) == false)
      throw(__SOD_IS_FULL);

  stacks[_i]->Put(a);
}

template<class T>
T TMulStack<T>::Get(int _i)
{
  if (IsEmpty(_i) == true)
    throw(__SOD_IS_EMPTY);
 
  return stacks[_i]->Get();
}

template<class T>
int TMulStack<T>::GetSize(int i)
{
  return stacks[i]->GetSize();
}

template<class T>
bool TMulStack<T>::IsEmpty(int _i)
{
  return stacks[_i]->IsEmpty();
}

template<class T>
bool TMulStack<T>::IsFull(int _i)
{
  return stacks[_i]->IsFull();
}
