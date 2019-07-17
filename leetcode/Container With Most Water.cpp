/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.  



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49


 */



//暴力解法

class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int max_vol = 0;
        for(int r = height.size()-1;r>0;r--)
        {
            int l = r;
            int vol;
            while(l>=0)
            {
                vol = min(height[l],height[r])*(r-l);
                max_vol = vol>max_vol?vol:max_vol;
                l--;
            }
        }
        
        return max_vol;
    }
};

//两点法

/*

    核心思想：从长度最长开始算，之后缩短长度增加高度

 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max_vol=0;
        int l=0,r=height.size()-1;
        
        while(l<r)
        {
            max_vol = max(max_vol,min(height[l],height[r])*(r-l));
            
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        
        return max_vol;
        
        
        
    }
};