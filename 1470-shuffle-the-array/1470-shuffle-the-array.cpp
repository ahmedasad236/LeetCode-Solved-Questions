class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n;
        vector<int> res;
        int size = 2 * n;
        while(j < size) {
            res.push_back(nums[i++]);
            res.push_back(nums[j++]);
        }
        return res;
    }
};