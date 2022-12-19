#pragma once 
#include <iostream>
#include "VectorIterator.h"

using namespace std;

template<typename T>
class TVectorIterator;

template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector();
  TDynamicVector(size_t size);
  TDynamicVector(T* arr, size_t s);
  TDynamicVector(const TDynamicVector& v);
  TDynamicVector(TDynamicVector&& v) noexcept;
  ~TDynamicVector();
  TDynamicVector& operator=(const TDynamicVector<T>& v);
  TDynamicVector& operator=(TDynamicVector<T>&& v) noexcept;

  size_t size() const noexcept;

  T& operator[](size_t indx);
  const T& operator[](size_t indx) const;
  T& at(size_t indx);
  const T& at(size_t indx) const;

  bool operator==(const TDynamicVector<T>& v) const noexcept;
  bool operator!=(const TDynamicVector<T>& v) const noexcept;

  TDynamicVector operator+(T value);
  TDynamicVector operator-(T value);
  TDynamicVector operator*(T value);

  TDynamicVector<T> operator+(const TDynamicVector<T>& v);
  TDynamicVector<T> operator-(const TDynamicVector<T>& v);
  T operator*(const TDynamicVector& v);

  friend istream& operator>>(istream& istr, TDynamicVector& v) 
  {
    for (size_t i = 0; i < v.sz; i++)
    {
      istr >> v.pMem[i];
    }
    return istr;
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    ostr << '(';
    for (size_t i = 0; i < v.sz - 1; i++)
    {
      ostr << v.pMem[i] << ',' << ' ';
    }
    ostr << v.pMem[v.sz - 1] << ')';
    return ostr;
  }
  TVectorIterator<T> begin();
  TVectorIterator<T> end();
};


template<typename T>
inline TDynamicVector<T>::TDynamicVector()
{
  sz = 1;
  pMem = new T();

}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(size_t size)
{
  if(size <= 0) throw "Error of input size"; 
  
  sz = size;
  pMem = new T[sz](); 

}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(T* arr, size_t size)
{
  if (size <= 0) throw "Error of input size;
  if (arr == nullptr) throw "Error: nullptr";

  sz = size;
  pMem = new T[sz];

  copy(arr, arr + size, pMem);
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(const TDynamicVector<T>& v)
{
  if (v.pMem == nullptr) throw "Error: nullptr";

  sz = v.sz;
  pMem = new T[sz];

  copy(v.pMem, v.pMem + sz, pMem);
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(TDynamicVector&& v) noexcept
{
  sz = v.sz;
  pMem = v.pMem;
  v.sz = 0;
  v.pMem = nullptr;
}

template<typename T>
inline TDynamicVector<T>::~TDynamicVector() 
{
  if (pMem != nullptr)
  {
    delete [] pMem;
    sz = 0;
    pMem = nullptr;
  }
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector<T>& v)
{
  if (this != &v) 
  {
    if (pMem != nullptr) delete [] pMem;

    sz = v.sz;
    pMem = new T[sz];
    copy(v.pMem, v.pMem + sz, pMem);
  }

  return *this;
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>&& v) noexcept
{
  if (this != &v) 
  {
    if (pMem != nullptr) delete [] pMem;

    sz = v.sz;
    pMem = v.pMem;

    v.sz = 0;
    v.pMem = nullptr;
  }

  return *this;
}

template<typename T>
inline size_t TDynamicVector<T>::size() const noexcept
{
  return sz;
}

template<typename T>
inline T& TDynamicVector<T>::operator[](size_t indx) 
{
  return pMem[indx];
}

template<typename T>
inline const T& TDynamicVector<T>::operator[](size_t indx) const 
{
  return pMem[indx];
}

template<typename T>
inline T& TDynamicVector<T>::at(size_t indx)
{
  if (indx >= sz || sz < 0) throw "Error of object's range";

  return pMem[indx];
}

template<typename T>
inline const T& TDynamicVector<T>::at(size_t indx) const
{
  if (indx >= sz || sz < 0) throw "Error of object's range";

  return pMem[indx];
}

template<typename T>
inline bool TDynamicVector<T>::operator==(const TDynamicVector& v) const noexcept
{
  if (sz != v.sz) 
    return false;

  for (size_t i = 0;i < sz; i++)
  {
    if (pMem[i] != v.pMem[i]) 
      return false;
  }

  return true;
}

template<typename T>
inline bool TDynamicVector<T>::operator!=(const TDynamicVector& v) const noexcept
{
  return !(*this == v);
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(T value)
{
  TDynamicVector<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + value;
  }

  return temp;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(T value)
{
  TDynamicVector<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - value;
  }

  return temp;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(T value)
{
  TDynamicVector<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] * value;
  }

  return temp;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector& v)
{
  if (sz != v.sz) throw "Error of sizes of objects";
  TDynamicVector<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + v[i];
  }

  return temp;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector& v)
{
  if (sz != v.sz) throw "Error of sizes of objects";
  TDynamicVector<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - v[i];
  }

  return temp;
}

template<typename T>
inline T TDynamicVector<T>::operator*(const TDynamicVector<T>& v) 
{
  if (sz != v.sz) throw "Error of sizes of objects";

  T temp = 0;

  for (size_t i = 0; i < sz; i++)
  {
    temp += pMem[i] * v[i];
  }

  return temp;
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::begin()
{
  return TVectorIterator<T>(*this);
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::end()
{
  return TVectorIterator<T>(*this, this->size - 1);
}