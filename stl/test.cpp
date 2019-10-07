#include<iostream>
#include "allocator.hpp"
using namespace std;
int main()
{
    int* p = reinterpret_cast<int*>(Alloc::allocate(4*sizeof(int)));

    for(int i=0;i<4;i++)
        p[i] = i;
    for(int i=0;i<4;i++)
        cout<<p[i]<<" ";
    
    cout<<endl;

    return 0;
}
