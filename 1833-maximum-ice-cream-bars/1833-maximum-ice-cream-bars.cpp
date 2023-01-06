class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int bars = 0;
        for(auto i : costs) {
            if(i <= coins) {
                coins -= i;
                bars++;
            } if(coins <= 0) return bars;
        }
        return bars;
    }
};