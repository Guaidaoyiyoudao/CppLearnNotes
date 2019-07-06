class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int pre_sum = 0;
        int sum = 0;
        int max_sum = 0;
        for(int i=0;i<nums.size();i++){
            
            pre_sum += nums[i];
            
            if(pre_sum>0){
                sum += nums[i];
                if(sum>max_sum){
                    max_sum = sum;
                }
                
            }else{
                sum = 0;
            }
                                           
            
                
        
            
        }
        
        return max_sum;
    }
};