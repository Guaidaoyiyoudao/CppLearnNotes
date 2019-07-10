/*


Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).





 */


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        if(nums.size()==3)
            return nums[0]+nums[1]+nums[2];
        
        int m = nums[0]+nums[1]+nums[2];
        bool found = false;
        for(int i=0;i<nums.size()&&!found;i++){
            
            int l = i+1;
            int r = nums.size()-1;
            
            while(l<r){
                
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<=abs(m-target)){
                    m = sum;
                }
                if(sum<target) l++;
                else if(sum>target) r--;
                else
                {
                    found = true;
                    break;
                }
               
                
            }
            
            
        }
        
        return m;
        
    }
};