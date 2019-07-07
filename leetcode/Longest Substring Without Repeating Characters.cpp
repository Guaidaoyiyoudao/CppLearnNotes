#include <set>
#include <iostream>

using namespace std;

int lenthOfLongestSubstring(string s) {
    int base,end;
    set<char> seen;
    base = end = 0;
    int count = 0;
    int max = 0;
    if(s.size()==1)
        return 1;
    for(int i=0;i < s.size();i++){


    }
    
    
    if(max<=count)
        max = count;
    return max;
}

int main()
{
    string s("ynyo");
    cout<<lenthOfLongestSubstring(s);
    return 0;
}