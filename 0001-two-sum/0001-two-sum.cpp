class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++) hash[nums[i]].push_back(i);
        for(auto i : nums) {
            int f = target - i;
            if(hash.find(f) != hash.end()) {
                  for(auto x : hash[i])
                      for(auto y : hash[f])
                          if(x != y) return {x, y};
            }
            
        }
        return {0, 0};
        
    }
};