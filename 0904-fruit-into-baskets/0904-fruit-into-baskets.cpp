class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> count;
        int unique = 0, currRes = 0, res = 0;
        int l = 0, r = 0, n = fruits.size();
        while(r < n) {
            currRes++;
            count[fruits[r]]++;
            if(count[fruits[r]] == 1) unique++;
            while(l < n && unique > 2) {
                currRes--;
                count[fruits[l]]--;
                if(count[fruits[l]] == 0) unique--;
                l++;
            }
            res = max(res, currRes);
            r++;
        }
        return res;
    }
};