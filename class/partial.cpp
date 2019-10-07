#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class func
{
public:
    void operator()()
    {
        cout<<"this is not POD"<<endl;
    }
};
template<typename T>
class func<T*>
{
public:
    void operator()()
    {
        cout<<"This is POD"<<endl;
    }
};


int main()
{
    func<vector<int>>()();
    func<int*>()();

    return 0;
}

