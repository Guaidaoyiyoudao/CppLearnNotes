#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//numsl里面的数据都在(1,100)
void counterSort(vector<int>& nums)
{

    vector<int> counter(101,0);
    vector<int> tmp(nums.size(),0);
    for(int i=0;i<nums.size();i++)
    {
        counter[nums[i]]++;
    }
    for(int i=2;i<=100;i++)
    {
        counter[i] += counter[i-1];
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        tmp[counter[nums[i]]-1] = nums[i];
        counter[nums[i]]--;
    }

    copy(tmp.begin(),tmp.end(),nums.begin());


}

int main()
{
    vector<int> nums{10,42,10,3,14,50,4,99,100,1};
    counterSort(nums);
    for(auto e:nums)
        cout<<e<<" ";
    cout<<endl;
    return 0;
}
