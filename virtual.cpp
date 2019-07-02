/*
    虚函数是用来对于类的方法进行动态绑定，即我们在编译时并不知道执行基类还是派生类的方法，通过动态绑定使在运行时通过
    类的实际类型对类函数进行调用。

    如果我们在用基类引用指向派生类的时候，用该引用调用虚函数的时候，调用的是基类还是派生的方法取决于该函数是否使虚函数，
    如果使虚函数，则是调用派生类的方法。

    当然，如果我们在派生类中没有重载虚类方法，而进行调用的话，则是调用基类的方法。
    ##

    只有虚函数可以被重载

    如果虚函数中提供了默认参数，即使派生类中重载的虚函数提供了不同的参数，但是使用的默认参数仍然是基类中虚函数所提供的
    默认参数值。 所以，在使用默认参数的虚函数的时候，基类和派生类提供的默认参数值要相同。

 */

#include<iostream>
#include<string>
using namespace std;
class Base
{
public:
    virtual void play(string s="Base class") const
    {
        cout<<"This is Base class!"<<endl;
        cout<<"base class"<<endl;

    }
};
class SubClass: public Base
{

public:
    void play(string s="derived class") const override
    {
        cout<<s<<endl;
        cout<<"derived class"<<endl;
    }

};

void tune(Base& b)
{
    b.play();
}

int main(void)
{
    SubClass s;
    tune(s);
    return 0;
}
