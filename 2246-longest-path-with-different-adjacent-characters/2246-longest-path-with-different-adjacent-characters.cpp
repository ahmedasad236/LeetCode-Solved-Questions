class Solution {
public:
    
    int dfs(int node, int prev, vector<vector<int>>& graph, string& s, int& res) {
        int mx1 = 0, mx2 = 0;
        for(auto ch : graph[node]) {
            if(node != prev) {
                int childLength = dfs(ch, node, graph, s, res);
                res = max(res, childLength);
                if(s[ch] == s[node]) continue;
                if(childLength > mx1) {
                    mx2 = mx1;
                    mx1 = childLength;
                } else if(childLength > mx2) mx2 = childLength;
            }
        }
        res = max(res, mx2 + mx1 + 1);
        return mx1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(parent.size());
        for(int i = 1; i < parent.size(); i++) {
            graph[parent[i]].push_back(i);
            //graph[i].push_back(parent[i]);
        }
        int res = 0;
        dfs(0, -1, graph, s, res);
        return res;
    }
};