class Solution {
public:
    
    vector<int> dfs(int node, int prev, const vector<vector<int>>& graph, string& labels, vector<int>& res) {
        vector<int> hash(26, 0);
        for(auto ch : graph[node]) {
            if(ch != prev) {
                vector<int> child = dfs(ch, node, graph, labels, res);
                hash[labels[ch] - 'a']++;
                for(int i=0;i<26;i++){
                    hash[i]+=child[i];
                }
            }
        }
        
        res[node] = hash[labels[node] - 'a'] + 1;
        return hash;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>>graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        dfs(0, -1, graph, labels, res);
        return res;
    }
};