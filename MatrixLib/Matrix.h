#pragma once
#include "Vector.h"
#include <iostream>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix();
  TDynamicMatrix(size_t size);
  TDynamicMatrix(const TDynamicMatrix<T>& m);

  using TDynamicVector<TDynamicVector<T>>::operator[];
  

  bool operator==(const TDynamicMatrix<T>& m) const noexcept;
  bool operator!=(const TDynamicMatrix<T>& m) const noexcept;

  TDynamicMatrix<T> operator+(const T& val);
  TDynamicMatrix<T> operator-(const T& val);
  TDynamicMatrix<T> operator*(const T& val);

  TDynamicMatrix<T> operator+(const TDynamicVector<T>& v);
  TDynamicMatrix<T> operator-(const TDynamicVector<T>& v);
  TDynamicVector<T> operator*(const TDynamicVector<T>& v);

  TDynamicMatrix<T> operator+(const TDynamicMatrix<T>& m);
  TDynamicMatrix<T> operator-(const TDynamicMatrix<T>& m);
  TDynamicMatrix<T> operator*(const TDynamicMatrix<T>& m);

  friend istream& operator>>(istream& istr, TDynamicMatrix<T>& m)
  {
    for (size_t i = 0; i < sz; i++)
    {
      for (size_t j = 0; j < sz; j++)
      {
        istr >> m[i][j];
      }
    }
    return istr; 
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix<T>& m)
  {
    ostr << '(';
    for (size_t i = 0; i < m.size(); i++)
    {
      for (size_t j = 0; j < m.size(); j++)
      {
        ostr << m[i][j] << ' ';
      }
      if (i != m.size() - 1) ostr << '\n';
    }
    ostr << ')';

    return ostr;
  }

};

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix() : TDynamicVector<TDynamicVector<T>>()
{
  sz = 0;
  pMem = 0;
}


template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(size_t size) : TDynamicVector<TDynamicVector<T>>(size) 
{
  if (size <= 0) throw "Error of size";
  for (size_t i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(sz);
}

template<class T>
inline TDynamicMatrix<T>::TDynamicMatrix(const TDynamicMatrix<T>& m) : TDynamicVector<TDynamicVector<T>>(m)
{
  if (m.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    sz = m.sz;
    pMem = new TDynamicVector<T>[sz];
    for (size_t i = 0; i < sz; i++)
      pMem[i] = m.pMem[i];
  }
}


template<typename T>
bool TDynamicMatrix<T>::operator==(const TDynamicMatrix<T>& m) const noexcept
{
  if (sz != m.sz) return false;
  for (size_t i = 0; i < sz; i++) 
  {
    if (pMem[i] != m[i]) return false;
  }
  return true;
}

template<typename T>
bool TDynamicMatrix<T>::operator!=(const TDynamicMatrix<T>& m) const noexcept 
{
  return !(*this == m);
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const T& value)
{ 
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + value;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const T& value)
{ 
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - value;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const T& value)
{ 
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] * value;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error of sizes of objects";

  TDynamicMatrix<T> temp(*this);
  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + v;
  }
  
  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error of sizes of objects";

  TDynamicMatrix<T> temp(*this);
  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - v;
  }

  return temp;
}

template<typename T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error of sizes of objects";

  TDynamicVector<T> temp(sz);

  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = pMem[i] * v;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error of sizes of objects";

  TDynamicMatrix<T> temp(*this);
  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + m[i];
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error of sizes of objects";

  TDynamicMatrix<T> temp(*this);
  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - m[i];
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error of sizes of objects";
  TDynamicMatrix<T> temp(sz);
  
  for (size_t i = 0; i < sz; i++)
  {
    for (size_t j = 0; j < sz; j++)
    {
      for (size_t k = 0; k < sz; k++)
      {
        temp[i][j] += pMem[i][k] * m[k][j];
      }
    }
  }

  return temp;
}
