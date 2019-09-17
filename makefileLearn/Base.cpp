#include "Base.hpp"
#include <iostream>

using namespace std;
Base::Base()
{
    cout<<"Base constructor"<<endl;
}
void Base::printInfo() const
{
    cout<<"Base [printInfo]"<<endl;
}
Base::~Base()
{
    cout<<"Base deconstructor"<<endl;
}
