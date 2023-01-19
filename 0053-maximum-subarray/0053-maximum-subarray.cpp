class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int totalSum = nums[0];
        int mx = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(currSum + nums[i] > nums[i]) currSum += nums[i];
            else currSum = nums[i];
            totalSum += nums[i];
            mx = max(mx, currSum);
        }
        return max(totalSum, mx);
    }
};