/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2   



 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int t = nums.size()/2;
        unordered_map<int,int> count;
        
        for(auto b=nums.cbegin();b!=nums.cend();b++){
            if(++count[*b]>t)
                return *b;
        }
        
        
        
        return nums[0];
        
        
        
    }
};

// 别人的解法
/*
思想：
    多数元素出现的次数大于 1/2, 所以只有多数元素在 
    nums[majorityIndex]==nums[i]?count++:count--;
    后，count大于0;
    
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            
            nums[majorityIndex]==nums[i]?count++:count--;
            if(count==0){
                majorityIndex = i;
                count = 1;
            }
        }
        
        return nums[majorityIndex];
        
        
        
        
    }
};