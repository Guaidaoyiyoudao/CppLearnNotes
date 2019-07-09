#include <memory>
#include <iostream>

using namespace std;
int main()
{   
   
    shared_ptr<int> p = make_shared<int> (2);

    cout<<"p's value:"<<*p<<endl;
    cout<<"p's counts:"<<p.use_count()<<endl;

    //after assignment 

    shared_ptr<int> q(p);
    cout<<"after assignment q's value:"<<*q<<endl;
    cout<<"after assignment p's counts:"<<p.use_count()<<endl;
    
     

    allocator<string> alloc;

    auto const p = alloc.allocate(10);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++,10,'c');
    alloc.construct(q++,10,'c');
    cout<<*(p+1)<<endl;
    return 0;
}