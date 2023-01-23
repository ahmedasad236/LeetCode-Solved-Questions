class Solution {
public:
    
    bool checkParenthesis(string s) {
        stack<char> st;
        for(auto c : s) {
            if(c == ')')
                if(st.empty()) return 0;
                else st.pop();
            else st.push(c);
        }
        return st.empty();
    }
    
    void solve(int n, int i, string curr, vector<string>& res) {
        if(i == n) {
            if(checkParenthesis(curr))
                res.push_back(curr);
            return;
        }
        solve(n, i + 1, curr + '(', res);
        solve(n, i + 1, curr + ')', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(2 * n, 0, "", res);
        return res;
    }
};