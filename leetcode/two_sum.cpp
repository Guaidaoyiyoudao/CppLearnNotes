#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> finded_map;
        int index = 0;
        vector<int> result;
        map<int,int>::iterator it;
        for(auto b = nums.cbegin();b != nums.cend();b++){

            int n = target - *b;
            if((it=finded_map.find(n))==finded_map.end()){
                finded_map[*b] = index;
            }else{
                result.push_back(it->second);
                result.push_back(index);
                return result;
            }
    
            index++;
        }
        return result;
    }
};