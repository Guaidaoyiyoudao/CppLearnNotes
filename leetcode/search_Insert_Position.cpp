/*


 */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        
        
        int start = 0;
        
        int end = size - 1;
        
        int mid = (start+end)/2;
        
        if(target>nums[end])
            return size;
        
        if(target<nums[start])
            return 0;
        
        while(end != mid && start != mid){
            
            if(nums[mid]<target){
                
                start = mid;
                
                mid = (start+end)/2;
                
                
            }else if(nums[mid]>target){
                
                end = mid;
                
                mid = (start+end)/2;
                
                
            }else
                return mid;
            
            
        }
        
        if(target>nums[mid])
            return mid+1;
        else
            return mid;
        
            
    
         
        
    }
};