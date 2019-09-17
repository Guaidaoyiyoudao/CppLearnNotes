#include"Base.hpp"
#include"Sub.hpp"


int main()
{
    Base* ptrs[2];
    ptrs[0] = new Base();
    ptrs[1] = new Sub();
    ptrs[0]->printInfo();
    ptrs[1]->printInfo();
    delete ptrs[0];
    delete ptrs[1];
    return 0;
}
