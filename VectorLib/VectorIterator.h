#pragma once
#include "Vector.h"

template<typename T>
class TDynamicVector;

template<typename T>
class TVectorIterator
{
public:
  TVectorIterator(TDynamicVector<T>& v);
  TVectorIterator(TDynamicVector<T>& v, size_t indx);
  TVectorIterator(TVectorIterator<T>& iv);

  bool operator==(const TVectorIterator<T>& v);
  bool operator!=(const TVectorIterator<T>& v);

  TVectorIterator operator++();
  TVectorIterator operator--();

  T& operator*();
private:
  TDynamicVector<T>& vector;
  size_t index;
};

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v) : vector(v)
{
  index = 0;  
}

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v, size_t indx) : vector(v)
{
  if(indx < 0 || indx >= v.size()) throw "Error: trying to set out of range iterator";
  index = indx;  
}

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TVectorIterator<T>& iv) : vector(iv.vector), index(iv.index)
{
}

template<typename T>
inline bool TVectorIterator<T>::operator==(const TVectorIterator<T>& v)
{
  if (&vector == &(v.vector) && index == v.index) return true;
  return false;   
}

template<typename T>
inline bool TVectorIterator<T>::operator!=(const TVectorIterator<T>& v)
{
  return !(*this == v);   
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator++() 
{
  TVectorIterator<T> temp(*this);
  temp.index++;

  if (temp.index >= temp.vector.size()) temp.index = vector.size() - 1;

  return temp;
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator--() 
{
  TVectorIterator<T> temp(*this);
  temp.index--;

  if (temp.index < 0) temp.index = 0;

  return temp;
}

template<typename T>
inline T& TVectorIterator<T>::operator*() 
{
  return vector.at(index);
}