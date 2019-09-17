#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

using namespace std;

class Animal
{

public:
    void eat()
    {
        cout<<"Animal eat something"<<endl;
    }
    virtual void bark()
    {
        cout<<"Animal bark!~"<<endl;
    }

    virtual ~Animal(){};

};
#endif
