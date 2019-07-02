

/*

    

 */
#include <iostream>

using namespace std;

class Base{

public:
    Base()
    {
        cout<<"Base constructor run"<<endl;
    }
    virtual ~Base()
    {
        cout<<"Base destructor run!"<<endl;
    }
};
class Derived: public Base{

public:
    Derived()
    {
        cout<<"Derived construtor run!"<<endl;
    }
    ~Derived()
    {
        cout<<"Derived destructor run!"<<endl;
    }
};

int main()
{
    Base * p = new Derived();

    delete p;

    return 0;

}