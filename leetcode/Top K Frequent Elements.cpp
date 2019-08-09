
#include<vector>
#include <map>
#include <queue>
using namespace std;
/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Accepted

 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> count;
    
        for(auto n:nums)
            count[n]++;
        
        auto cmp = [&count](int left,int right){
            return count[right]>count[left];
        };
        priority_queue<int,vector<int>,decltype(cmp)> heap(cmp);
        
        for(auto it=count.cbegin();it!=count.cend();it++)
        {
            heap.push(it->first);
        }
        
        
        for(int i=0;i<k;i++)
        {
            result.push_back(heap.top());
            heap.pop();
        }
        
        
        
        return result;
        
        
        
    }
        

};