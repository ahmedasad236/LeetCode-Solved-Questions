class Solution {
public:
    
    char chars[10][4] = {
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'a', 'b', 'c', '0'},
        {'d', 'e', 'f', '0'},
        {'g', 'h', 'i', '0'},
        {'j', 'k', 'l', '0'},
        {'m', 'n', 'o', '0'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', '0'},
        {'w', 'x', 'y', 'z'}
    };
    
    void solve(string s, int index, string curr, vector<string>& res) {
        if(index == s.size()) {
          if(curr != "")
            res.push_back(curr);
          return;
        } 
        
        for(auto c : chars[s[index] - '0']) {
            if(c == '0') continue;
            curr += c;
            solve(s, index + 1, curr, res);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        solve(digits, 0, "", res);
        return res;
    }
};