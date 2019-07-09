//这个解法是讨论区copy的
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            //大于0,后面的都大于0，退出循环
            if (nums[i] > 0) break;
            //去掉重复
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0-nums[i];
            int left = i+1, right = n-1;
            while(left < right) {
                int sum = nums[left]+nums[right];

                //等于0 
                if(sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    //去掉重复
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left; --right;
                } else if(sum > target) {
                    right --;
                } else {
                    left ++;
                }
            }
        }
        return res;
        
    }
};