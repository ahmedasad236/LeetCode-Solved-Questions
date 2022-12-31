class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto c : s) mp[c]++;
        if(mp.size() == 1) return mp[s[0]];
        int mxLength = 0;
        bool hasOdd = 0;
        for(auto p : mp) {
            if(!(p.second & 1)) mxLength += p.second;
            else mxLength += p.second - 1, hasOdd = 1;
        }
        
        return hasOdd? mxLength + 1 : mxLength;
    }
};