class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        if(prices.size()==0)
            return 0;
        if(prices.size()==1)
            return 0;
        int last = prices[0];
        for(int i=1;i<prices.size();i++){

            if(prices[i]>last){
                profit += prices[i] - last;
            }
            last = prices[i];
        }
        return profit;
    }
};