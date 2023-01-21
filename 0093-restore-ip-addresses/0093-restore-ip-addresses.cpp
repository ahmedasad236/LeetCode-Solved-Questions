class Solution {
public:
    
    bool valid(string s, int start, int length) {
        if(s[start] == '0') return length == 1;
        if(length == 3) return s.substr(start, length) <= "255";
        return s[start] != '0';
    }
    
    void sol(const string& s, int startIndex, vector<int> dots, vector<string>& res) {
        int remainingLength = s.size() - startIndex;
        int remainingIntegers = 4 - dots.size();
        if(remainingLength > remainingIntegers * 3 || remainingLength < remainingIntegers) return;
        if(remainingIntegers == 1)  {
            if(valid(s, startIndex, remainingLength)) {
                string t = "";
                int last = 0;
                for(auto dot : dots) {
                    t += s.substr(last, dot);
                    t += '.';
                    last += dot;
                }
                t += s.substr(startIndex);
                res.push_back(t);
            }
            return;
        }
        
        for(int i = 1; i <= min(3, remainingLength); i++) {
            
            if(valid(s, startIndex, i)) {
                dots.push_back(i);
                sol(s, startIndex + i, dots, res);
                dots.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<int> dots;
        vector<string> res;
        sol(s, 0, dots, res);
        return res;
    }
};