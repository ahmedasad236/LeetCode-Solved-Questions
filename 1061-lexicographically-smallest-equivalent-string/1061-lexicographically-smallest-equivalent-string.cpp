class Solution {
public:
    
    int parents[26] = {0};
    int get(int a) {
        return parents[a] = (a == parents[a] ? a : get(parents[a]));
    }
    void unionSets(int a, int b) {
        a = get(a);
        b = get(b);
        if(a < b)
            parents[b] = a;
        else parents[a] = b;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++) parents[i] = i;
        for(int i = 0; i < s2.size(); i++) {
            unionSets(s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for(auto c : baseStr) {
            res += (char)(get(c - 'a') + 'a');
        }
        return res;
    }
};