class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return dpRec(n, dp);
    }
    
    int dpRec(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        dp[n] = dpRec(n - 2, dp) + dpRec(n - 1, dp); 
        return dp[n];
    }
};