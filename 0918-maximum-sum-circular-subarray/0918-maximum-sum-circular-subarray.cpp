class Solution {
public:

    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMx = nums[0], currMn = nums[0], totalMx = nums[0], totalMn = nums[0], sum = nums[0];
        for(int i = 1; i < n; i++) {
            if(currMx + nums[i] > nums[i]) {
                currMx += nums[i];
            } else {
                currMx = nums[i];
            }
            totalMx = max(totalMx, currMx);
            
            if(currMn + nums[i] < nums[i]) {
                currMn += nums[i];
            } else {
                currMn = nums[i];
            }
            totalMn = min(totalMn, currMn);
            sum += nums[i];
        }
        if(sum == totalMn) return totalMx;
        return max(totalMx, sum - totalMn);
    }
};