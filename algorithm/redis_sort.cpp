#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxBit(vector<int>& nums)
{
   int max_value = *max_element(nums.begin(),nums.end());
   
   int d = 1;
   int p = 10;
   while(max_value>=p)
   {
       max_value /= 10;
       d++;
   }

   return d;
}

void redis_sort(vector<int>& nums)
{

    int d = maxBit(nums);
    vector<int> counter(10,0);
    vector<int> tmp(nums.size(),0);
    int redis = 1;
    int k;
    for(int i=1;i<=d;i++)
    {

        for(int i=0;i<counter.size();i++)
            counter[i]=0;

        for(int j=0;j<nums.size();j++)
        {
          k = (nums[j]/redis)%10;
          counter[k]++;
        }
        for(int j=1;j<10;j++)
        {
            counter[j] += counter[j-1];
            
        }

        for(int j=nums.size()-1;j>=0;j--)
        {
            k = (nums[j]/redis)%10;
            tmp[counter[k]-1] = nums[j];
            counter[k]--;
        }
        copy(tmp.begin(),tmp.end(),nums.begin());

    for(auto e:nums)
        cout<<e<<" ";
    cout<<endl;


        redis *= 10;
        

        
    }

}

int main()
{

    vector<int> nums{53,3,542,748,14,214,154,63,616};
    redis_sort(nums);
    for(auto e:nums)
        cout<<e<<" ";
    cout<<endl;

    return 0;
}
