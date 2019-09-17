#include <iostream>
#include "animal.hpp"
using namespace std;

class Dog:
    public Animal
{

    
public:
    Dog(int age):_age(age){}
    void bark()

    {
        cout<<"Dog bark!!~"<<endl;
    }

    
    virtual ~Dog(){}
private:
    int _age;
};
