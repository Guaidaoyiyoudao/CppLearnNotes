#include <iostream>
#include <climits>
using namespace std;
bool isPalindrome(int x) {
    long long re=0;
    int c;
    int t = x;

    if(x<0)
        return false;
    while(t!=0){
        c = t % 10;
        t = t/10;
        re = re*10 + c; 
    }
    return x==re;
}

int main(void)
{
    if(isPalindrome(1000000001))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}