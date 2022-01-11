https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0], maxP = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                maxP = max(maxP, prices[i]-minimum);
            }
            else {
                minimum = min(minimum, prices[i]);
            }
        }
        return maxP;
    }
};