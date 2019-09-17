#ifndef BASE_HPP
#define BASE_HPP
#include<iostream>

class Base
{
public: 
    Base();
    virtual void printInfo() const;
    virtual ~Base();
private:
    int count=0;
    
};
#endif
