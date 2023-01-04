class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for(auto i : tasks) mp[i]++;
        int res = 0;
        for(auto p : mp) {
            if(p.second == 1) return -1;
            int x = p.second;
            //cout << p.first << ' ' << p.second << '\n';
            while(x > 0) {
                if(x - 3 != 1) x -= 3;
                else x -= 2;
                res++;
            }
        }
        return res;
    }
};