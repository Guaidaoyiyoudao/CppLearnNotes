class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = "";
        if(strs.size()==0)
            return prefix;
        
        prefix = strs[0];
        
        for(int i=1;i<strs.size();i++){
            int k=0;
            for(;k<prefix.size()&&k<strs[i].size();k++){
                
                if(prefix[k]!=strs[i][k]){
                    
                    prefix = prefix.substr(0,k);
                    break;
                }
                
            }
            prefix = prefix.substr(0,k);
        }
        
        return prefix;
    }
        
        
};