#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void quickSort(vector<int>& nums,int beg,int end)
{
    if(beg>=end)
        return;
   int index = beg;
   int pivot = nums[index];
   int left = beg,right = end;
   while(left<right)
   {
       while(left<right&&nums[right]>=pivot)
           right--;
       while(left<right&&nums[left]<=pivot)
           left++;
       if(left<right)
           swap(nums[left],nums[right]);
   
   }

   nums[index] = nums[right];
   nums[right] = pivot;
   for(auto e:nums)
       cout<<e<<" ";
   cout<<endl;
   quickSort(nums,beg,right-1);
   quickSort(nums,left+1,end);
    
}
int main()
{

    vector<int> nums{3,1,4,2,5};
    quickSort(nums,0,nums.size()-1);
    return 0;
}

