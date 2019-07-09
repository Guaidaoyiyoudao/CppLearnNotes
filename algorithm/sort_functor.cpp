#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



template <typename T>
class Functor{
public:
    Functor() = default;
    Functor(T _y):y(_y){};
    T operator() (T&& x){
        return x+y;
    };
private:
    T y=0;
};
int main()
{
    vector<int> a =  {10,4,3,2,1,5,6,9,8,7};

    sort(a.begin(),a.end(),greater<int>());

    for(auto e: a)
        cout<<e<<" ";

    cout<<Functor<double>(4.0)(5.0);
    return 0;
    
}