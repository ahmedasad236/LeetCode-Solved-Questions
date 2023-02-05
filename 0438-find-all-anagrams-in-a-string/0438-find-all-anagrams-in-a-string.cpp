class Solution {
public:
    
    bool check(vector<int>& v) {
        for(auto i : v)
            if(i) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26, 0);
        for(auto c : p) hash[c - 'a']++;
        vector<int> res;
        int sizeP = p.size();
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']--;
            if(i >= sizeP - 1) {
                if(check(hash)) res.push_back(i - sizeP + 1);
                hash[s[i - sizeP + 1] - 'a']++;
            }
        }
        return res;
    }
};