class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] < c || (j > 0 && strs[j][i] < strs[j - 1][i])) {
                    res++;
                    break;
                }
                
            }
        }
        return res;
    }
};