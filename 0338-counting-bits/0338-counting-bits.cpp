class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++) {
            int cnt = 0, temp = i;
            while(temp) {
                cnt++;
                temp = temp & (temp - 1);
            }
            res[i] = cnt;
        }    
        return res;
    }
};