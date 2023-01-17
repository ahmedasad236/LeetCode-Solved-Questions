class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int totalOnes = count(s.begin(),s.end(),'1');
        int n = s.size();
        int currOnes = 0;
        int res = min(totalOnes, n - totalOnes);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') currOnes++;
            int currSol = currOnes + (n - i - 1 - (totalOnes - currOnes));
            res = min(res, currSol);
        }
        return res;
    }
};