class Solution {
public:
    
    bool checkNonDecreasing(const vector<int>& v) {
        for(int i = 1; i < v.size(); i++)
            if(v[i] < v[i - 1]) return false;
        return true;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        int total = 1 << n;
        for(int k = 1; k <= total; k++) {
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                if(k & (1 << i)) temp.push_back(nums[i]);
            }
            if(temp.size() > 1 && checkNonDecreasing(temp)) res.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto i : res) ans.push_back(i);
        return ans;
    }
};