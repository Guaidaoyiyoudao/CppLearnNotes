/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:



 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        int current = nums[0];
        for(auto b=nums.begin()+1;b!=nums.end();){
            
            if(current==*b){
                b = nums.erase(b);
            }else{
                current = *b;
                b++;
            }
            
        }
        return nums.size();
    }
};