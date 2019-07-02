#include<iostream>
using namespace std;
int main()
{
    int sum,num;
    sum = 0;
    while(cin>>num)
    {
        if(num>=20)
        {
            num -= 4;
        }
        sum += num;
    }
    cout<<sum;
    return 0;
}