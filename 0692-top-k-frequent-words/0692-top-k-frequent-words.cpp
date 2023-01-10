class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }

    // Function to sort the map according
    // to value in a (key-value) pairs
     vector<pair<string, int>> sortMap(map<string, int>& M) {

        // Declare vector of pairs
        vector<pair<string, int>> A;

        // Copy key-value pair from Map
        // to vector of pairs
        for (auto& it : M) {
            A.push_back(it);
        }

        // Sort using comparator function
        sort(A.begin(), A.end(), cmp);

        return A;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto word : words) mp[word]++;
        vector<pair<string, int>> sorted = sortMap(mp);
        //for(auto word : sorted) cout << word.first << '\n';

        vector<string> res;
        for(int i = 0, j = sorted.size() - 1; i < k; i++, j--)
            res.push_back(sorted[j].first);
        return res;
    }
};