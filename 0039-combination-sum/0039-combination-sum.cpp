class Solution {
public:
    
    void solve(const vector<int>& candidates, int indx, int target,  vector<int> curr, set<vector<int>>& res) {
        if(target <= 0) {
            if(target == 0) {
                sort(curr.begin(), curr.end());
                if(res.count(curr) == 0)
                    res.insert(curr);
            }
            return;
        }
        for(int i = indx; i < candidates.size(); i++) {
            target -= candidates[i];
            curr.push_back(candidates[i]);
            solve(candidates, i, target, curr, res);
            target += candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        solve(candidates, 0, target, {}, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};