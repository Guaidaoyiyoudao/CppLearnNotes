#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void f1(vector<int>& nums)
{ 
    for(auto a:nums)
    {
        cout<<"f1 funtion: print "<<a<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

class F
{
public:
    F(vector<int>& n):nums(n){}
    void operator()(){
        for(auto a:nums)
        {
            cout<<"F class: print "<<a<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

private:
    vector<int>& nums;
};
int main()
{
    vector<int> n1{1,2,3,4,5,6,7,8,9,10};
    vector<int> n2{10,9,8,7,6,5,4,3,2,1};
    thread t1 {f1,ref(n1)};
    thread t2 {F(n2)};

    t1.join();
    t2.join();
    return 0;
}