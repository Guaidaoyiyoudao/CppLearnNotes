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
    class findKey{
    public:
        findKey(char k):key(k){}
        bool operator ()(pair<char,int> p){
            if(p.first==key)
                return true;
            else
                return false;    
        }
        
    private:
        char key;
    };
    int lengthOfLongestSubstring(string s) {
        
        int max_length=0;
        vector<pair<char,int>> chars;
        
        for(int i=0;i<s.size();){
            auto it = find_if(chars.begin(),chars.end(),findKey(s[i]));
            if(it==chars.end())
            {
                chars.push_back(pair<char,int>(s[i],i));
                if(max_length<chars.size())
                    max_length++;
                i++;
                
            }else{
                
                int index = it->second+1;
                chars.erase(chars.begin(),++it);
                
            }
                
            
        }
        
        return max_length;
        
        
        
    }
};