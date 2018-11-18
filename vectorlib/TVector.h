#pragma once

template <class T>
class TVector
{
protected:
	int l; //lenght
	T* p; //pointer
public:
	TVector(int n);
	TVector(TVector<T>& A);
	~TVector();
	int GetSize(); //return lenght
	virtual TVector<T>& operator = (TVector<T> &A);
	virtual T& operator [](int i);
	virtual TVector<T> operator + (TVector<T> &A);
	virtual TVector<T> operator - (TVector<T>& A);
	virtual TVector<T> operator * (TVector<T> &A);
};

template <class T>
TVector<T>::TVector(int n)
{
	if (n <= 0)
		throw(1);
	else
	{
		l = n;
		p = new T[l];
	}
}

template <class T>
TVector<T>::TVector(TVector<T>& A)
{
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];
}

template <class T>
TVector<T>::~TVector()
{
	delete[] p;
}

template <class T>
int TVector<T>::GetSize()
{
	return l;
}

template<class T>
TVector<T>& TVector<T>::operator=(TVector<T>& A)
{
	delete[] p;
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template<class T>
T& TVector<T>::operator[](int i)
{
	if (i >= l || i < 0)
		throw(1);
	else
		return p[i];
}

template<class T>
TVector<T> TVector<T>::operator+(TVector<T>& A)
{
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator-(TVector<T>& A)
{
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(TVector<T>& A)
{
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * A.p[i];
	return R;
}
