#include "iterator.hpp"
template<typename T>
Iterator<T>::Iterator(const Iterator<T>& other)
{
    this->it = other.it;
}
template<typename T>
Iterator<T>::Iterator(Iterator<T>&& other)
{
    this->it = other.it;
    other.it = nullptr;
}
template<typename T>
Iterator<T>& Iterator<T>::operator =(const Iterator<T>& other)
{
   this->it = other.it; 
}
template<typename T>
Iterator<T>& Iterator<T>::operator=(Iterator<T>&& other)
{
    this->it = other.it;
    other.it = nullptr;
}
template<typename T>
typename Iterator<T>::value_type& Iterator<T>::operator*()
{
    return *(this->it);    
}
template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    this->it++;
    return *this;
}
template<typename T>
Iterator<T>& Iterator<T>::operator--()
{
    this->it--;
    return *this;
}
template<typename T>
Iterator<T>& Iterator<T>::operator++(int)
{
    Iterator<T> old(*this);
    this->it++;
    return old;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--(int)
{
    Iterator<T> old(*this);
    this->it--;
    return old;
}
template<typename T>
bool Iterator<T>::operator ==(const Iterator<T>& other)const
{
    return this->it==other.it;
}

template<typename T>
bool Iterator<T>::operator !=(const Iterator<T>& other)const
{
    return !(this->it==other.it);
}
