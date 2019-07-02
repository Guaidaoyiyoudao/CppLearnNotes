#include <vector>
#include <iostream>
using namespace std;
bool findNumber(vector<int> a,int value)
{
    for(auto b = a.begin();b!=a.end();b++)
    {
        if(*b==value)
            return true;
    }
    return false;
}
vector<int>::iterator findNumberIterator(vector<int> a,int value)
{
    for(auto b = a.begin();b!=a.end();b++)
    {
        if(*b==value)
            return b;
    }
    return nullptr;
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    int v = 5;
    vector<int>::iterator i;
    if(i=findNumberIterator(a,v))
        cout<<"find it!~"<<endl;;
        
    return 0;e