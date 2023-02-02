class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> alph;
        for(int i = 0, n = order.size(); i < n; i++)
            alph[order[i]] = i;
        for(int i = 1; i < words.size(); i++) {
            int curr1 = 0, curr2 = 0;
            while(curr1 < words[i - 1].size() && curr2 < words[i].size() && words[i - 1][curr1] == words[i][curr2]) curr1++, curr2++;
            
            if(curr1 < words[i - 1].size() && curr2 < words[i].size() && alph[words[i - 1][curr1]] > alph[words[i][curr2]]) return false;
            
            if(curr1 < words[i - 1].size() && curr2 == words[i].size()) return false;
            
            
            
        }
        return true;
    }
};