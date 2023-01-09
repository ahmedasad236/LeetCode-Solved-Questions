class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1, st2;
        for(auto c : s) {
            if(c == '#') {
                if(!st1.empty())
                    st1.pop();
            }
            else st1.push(c); 
        }
        
        for(auto c : t) {
            if(c == '#') {
                if(!st2.empty())
                    st2.pop();
            }
            else st2.push(c); 
        }
        
        while(!st1.empty() && !st2.empty()) {
            char c1 = st1.top(), c2 = st2.top();
            if(c1 != c2) return false;
            st1.pop();
            st2.pop();
        }
        
        return st1.empty() && st2.empty();
        
    }
};