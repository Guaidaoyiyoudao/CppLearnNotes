#include <iostream>
#include "Sub.hpp"

using namespace std;

Sub::Sub()
{
    cout<<"Sub constructor in Sub"<<endl;
}
Sub::~Sub()
{
    cout<<"Sub deconstructor in Sub"<<endl;
}
void Sub::printInfo() const
{
    cout<<"Sub [printInfo]"<<endl;
}
