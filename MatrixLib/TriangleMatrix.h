#pragma once
#include "Vector.h"

template <class T>
class TTrangleMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using::TDynamicVector<TDynamicVector<T>>::pMem;
  using::TDynamicVector<TDynamicVector<T>>::sz;
public:
  TTrangleMatrix(size_t size1);
  TTrangleMatrix(size_t size, const T* arr);
  TTrangleMatrix(const TTrangleMatrix<T>& mat) noexcept;
  TTrangleMatrix(TTrangleMatrix<T>&& mat);

  bool operator == (const TTrangleMatrix<T>& mat) const noexcept;
  bool operator != (const TTrangleMatrix<T>& mat) const noexcept;

  TTrangleMatrix<T> operator + (const TTrangleMatrix<T>& mat);
  TTrangleMatrix<T> operator - (const TTrangleMatrix<T>& mat);
  TTrangleMatrix<T> operator * (const TTrangleMatrix<T>& mat);

  TTrangleMatrix<T> operator = (TTrangleMatrix<T>&& mat);
  TTrangleMatrix<T> operator = (const TTrangleMatrix<T>& mat);
};

template<class T>
inline TTrangleMatrix<T>::TTrangleMatrix(size_t size1) : TDynamicVector<TDynamicVector<T>>(size1)
{
  sz = size1;
  for (size_t i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(i + 1);
}

template<class T>
inline TTrangleMatrix<T>::TTrangleMatrix(size_t size, const T* arr) : TTrangleMatrix<T>(size)
{
  if (size == 0)
    throw out_of_range("size must be greater than zero");
  size_t iter = 0;
  for (size_t i = 0; i < sz; i++)
    for (int j = 0; j <= i; j++)
    {
      pMem[i][j] = arr[iter];
      iter++;
    }
}

template<class T>
inline TTrangleMatrix<T>::TTrangleMatrix(const TTrangleMatrix<T>& mat) noexcept
{
  if (mat.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    sz = mat.sz;
    pMem = new TDynamicVector<T>[sz];
    for (size_t i = 0; i < sz; i++)
      pMem[i] = mat.pMem[i];
  }
}

template<class T>
inline TTrangleMatrix<T>::TTrangleMatrix(TTrangleMatrix<T>&& mat)
{
  pMem = mat.pMem;
  sz = mat.sz;
  mat.pMem = nullptr;
  mat.sz = 0;
}

template<class T>
inline bool TTrangleMatrix<T>::operator==(const TTrangleMatrix<T>& mat) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator ==(mat);
}

template<class T>
inline bool TTrangleMatrix<T>::operator!=(const TTrangleMatrix<T>& mat) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator !=(mat);
}

template<class T>
inline TTrangleMatrix<T> TTrangleMatrix<T>::operator+(const TTrangleMatrix<T>& mat)
{
  if (sz != mat.sz)
    throw "different sizes";
  TTrangleMatrix<T> res(sz);
  for (size_t i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] + mat.pMem[i];
  return res;
}

template<class T>
inline TTrangleMatrix<T> TTrangleMatrix<T>::operator-(const TTrangleMatrix<T>& mat)
{
  if (sz != mat.sz)
    throw "different sizes";
  TTrangleMatrix<T> res(sz);
  for (size_t i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] - mat.pMem[i];
  return res;
}

template<class T>
inline TTrangleMatrix<T> TTrangleMatrix<T>::operator*(const TTrangleMatrix<T>& mat)
{
  if (sz != mat.sz)
    throw "different sizes";
  TTrangleMatrix<int> res(sz);
  for (size_t row = 0; row < sz; row++)
    for (size_t col = 0; col <= row; col++)
    {
      T sum = 0;
      for (size_t k = col; k <= row; k++)
        sum += pMem[row][k] * mat.pMem[k][col];
      res.pMem[row][col] = sum;
    }
  return res;
}

template<class T>
inline TTrangleMatrix<T> TTrangleMatrix<T>::operator=(TTrangleMatrix<T>&& mat)
{
  if (this != &mat)
  {
    if (pMem != nullptr)
      delete[] pMem;

    pMem = mat.pMem;
    sz = mat.sz;
    mat.pMem = nullptr;
    mat.sz = 0;
  }
  else
    throw "copy itself";
  return *this;
}

template<class T>
inline TTrangleMatrix<T> TTrangleMatrix<T>::operator=(const TTrangleMatrix<T>& mat)
{
  if (this != &mat)
  {
    sz = mat.sz;
    if (pMem != nullptr)
      delete[] pMem;
    pMem = new TDynamicVector<T>[sz];
    for (size_t i = 0; i < mat.sz; i++)
      pMem[i] = mat.pMem[i];
  }
  else
    throw "copy itself";
  return *this;
}

template<class T>
ostream& operator <<(ostream& ostr, TTrangleMatrix<T>& p)
{
  for (size_t i = 0; i < p.size(); i++)
  {
    auto v = p[i];
    for (size_t j = 0; j <= i; j++)
    {
      ostr << p[i][j] << "\t";
    }
    ostr << endl;
  }
  return ostr;
}

template<class T>
istream& operator >>(istream& istr, TTrangleMatrix<T>& p)
{
  size_t size;
  istr >> size;
  TTrangleMatrix<T> istrmatrix(size);
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      istr >> istrmatrix[i][j];
  p = istrmatrix;
  return istr;
}