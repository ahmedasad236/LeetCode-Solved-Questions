class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        map<char, int> mp;
        int l = 0, r = 0, n = s.size(), mxChar = 0;
        while(r < n) {
            mp[s[r]]++;
            mxChar = max(mxChar, mp[s[r]]);
            if(r - l + 1 - mxChar > k) mp[s[l]]--, l++;
            res = max(res, r - l + 1);
            r++;
        }
        
        return res;
    }
};