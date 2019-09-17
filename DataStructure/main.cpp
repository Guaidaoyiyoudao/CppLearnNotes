#include <iostream>
#include "Vector.cpp"
using namespace std;
int main()
{

    Vector<int> a(10,0);
    for(auto e:a)
        cout<<" "<<e;
    cout<<endl;
    return 0;
}

