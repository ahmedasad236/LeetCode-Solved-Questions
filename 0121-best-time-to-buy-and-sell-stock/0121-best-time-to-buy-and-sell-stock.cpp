class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit = 0;
        int mnElement = 1e9;
        for(int i = 1, n = prices.size(); i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                int currProfit = prices[i] - prices[i - 1];
                int currMn = prices[i - 1];
                mxProfit = max(currProfit, max(prices[i] - mnElement, mxProfit));
                mnElement = min(mnElement, currMn);
            }
        }
        return mxProfit;
    }
};