/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.





 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_length{1};
        int left=0,right=1;
        if(s.empty())
            return 0;
        while(right<s.size())
        {
            
            for(int i=left;i<right;i++)
                if(s[i]==s[right]){
                    left = i+1;
                    break;
                }
            right++;
            if(max_length<(right-left))
                max_length = right-left;
            
        }
         return max_length;   
    }
};