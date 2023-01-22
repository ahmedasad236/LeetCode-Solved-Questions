class Solution {
public:
    
    bool isPalindrome(string& s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - i - 1])
                return false;
        } 
        return true;
    }
    
    
    vector<vector<string>> recPartition(string s) {
        vector<vector<string>> res;
        int n = s.size();
        if(n == 1) {
            vector<string> inner;
            string temp = "";
            temp += s[0];
            inner.push_back(temp);
            res.push_back(inner);
            return res;
        }
        
        for(auto list : recPartition(s.substr(1))) {
            vector<string> separate(list);
            string temp = "";
            temp += s[0];
            separate.insert(separate.begin(), temp);
            vector<string> append(list);
            append[0].insert(append[0].begin(), s[0]);
            res.push_back(append);
            res.push_back(separate);
        }
        return res;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allPartitions = recPartition(s);
        vector<vector<string>> res;
        for(auto part : allPartitions) {
            bool palindrome = 1;
            for(auto str : part) {
                if(!isPalindrome(str)) {
                    palindrome = 0;
                    break;
                }
            }
            if(palindrome) res.push_back(part);
        }
        
        return res;
    }
};