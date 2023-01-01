class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, bool> vis;
        vector<string> splitted;
        string word = "";
        for(auto c : s) {
            if(c == ' ') {
                splitted.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        splitted.push_back(word);
        if(splitted.size() != pattern.size()) return false;
        for(int i = 0; i < pattern.size(); i++) {
            if(mp[pattern[i]] == "")  {
                mp[pattern[i]] = splitted[i];
                if(vis[splitted[i]]) return false;
                vis[splitted[i]] = 1;
            }
            else if(mp[pattern[i]] != splitted[i]) return false;
        }
        return true;
    }
};