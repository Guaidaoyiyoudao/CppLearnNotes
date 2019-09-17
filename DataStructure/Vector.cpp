#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<stdexcept>
#include<initializer_list>
#include "iterator.hpp"
template<typename T>
class Vector
{
	using value_type = T;

public:
	//constructor
	Vector() = default;
	explicit Vector(int sz):_size(sz),elem{new value_type[sz]},used{0}{}
    Vector(int size,value_type value)
    {
        this->_size = size;
        this->elem = new value_type[_size];
        this->used = size;
        for(int i=0;i<size;i++)
        {
            this->elem[i] = value;
        }    
    }
	Vector(std::initializer_list<value_type> lst)
	{
		elem = new value_type[lst.size()];
		_size = static_cast<int>(lst.size());
		used = static_cast<int>(lst.size());
	}
	
	//copy constructor
	Vector(Vector& v)
	{
		this->_size = v._size;
		this->elem = new value_type[_size];
		this->used = v.used;
		for(int i=0;i<used;i++)
			this->elem[i] = v[i];
	}
	//copy assign
	Vector& operator =(const Vector& r)
	{
		this->_size = r._size;
        delete[] this->elem;
		this->elem = new value_type[this->_size];
		this->used = r.used;

		for(int i=0;i<used;i++)
			this->elem[i] = r[i];
		return *this;	
	}
    //copy move constructor
	Vector(Vector&& r)
	{
		this->elem = r.elem;
		this->_size = r._size;
		this->used = r.used;

		r.elem = nullptr;
		r._size = 0;
		r.used = 0;
	}

	void push_back(const value_type& value)
	{
		if(used<_size)
		{
			//has space
			elem[used++] = value;
		}
		else
		{
			this->reallocate();
			elem[used++] = value;
		}
		
	}
    void push_back(value_type&& value)
    {
        
		if(used<_size)
		{
			//has space
			elem[used++] = value;
		}
		else
		{
			this->reallocate();
			elem[used++] = value;
         }
    }
	value_type& operator [](int index)
	{
		if(index<0||index>=_size)
			throw std::out_of_range("Index out of range in vector");
		return elem[index];
	}
	const value_type& operator[](const int index)const
	{
		if(index<0||index>=_size)
			throw std::out_of_range("Index out of range in vector");
		return elem[index];
	}


	int capacity() const
	{
		return this->_size;
	}
	int size() const
	{
		return this->used;
	}
	value_type front()const
	{

		if(used>0) return elem[0];
		else return 0;
	}
	~Vector()
	{
		if(elem!=nullptr)
			delete[] elem;
	}



private:
	int _size = 0;
	int used = 0;
	value_type* elem = nullptr;
    Iterator<value_type> b();
    Iterator<value_type> e();

	void reallocate()
	{
		value_type * new_elem = new value_type[_size*2];
		
		for(int i=0;i<used;i++)
			new_elem[i] = elem[i];
		_size *= 2;
		delete[] elem;
		elem = new_elem;
	}
};
template<typename T>
Vector<T> operator +(const Vector<T>& a,const Vector<T>& b)
{
	if(a.size()!=b.size())
		throw std::length_error("two vector size not equal");
	Vector<T> res(a.size());
	for(int i=0;i<a.size();i++)
		res[i] = a[i] + b[i];
	return res;
}
template<typename T>
Iterator<T> begin(Vector<T>& x)
{
	return x.size()?Iterator<T>(&x[0]):nullptr;
}
template<typename T>
Iterator<T> end(Vector<T>& x)
{
	return x.size()?Iterator<T>(&x[x.size()]):nullptr;
}
	
#endif

