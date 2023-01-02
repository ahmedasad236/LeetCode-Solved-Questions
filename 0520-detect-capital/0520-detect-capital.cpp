class Solution {
public:
    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(auto c : word)
            if(isCapital(c))cap++;
        return cap == word.size() || cap == 0 || (cap == 1 && isCapital(word[0])); 
    }
};