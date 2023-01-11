class Solution {
public:
    
    int dfs(int node, const vector<vector<int>>& graph, const vector<bool>& hasApple, int depth, int prev) {
        
        int res = 0;
        for(auto i : graph[node]) {
            if(i != prev) {
                int temp = dfs(i, graph, hasApple, depth + 1, node);
                if(temp) res += temp - depth;
            }
                
        }
        return res || hasApple[node] ? res + depth : 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(0, graph, hasApple, 0, -1) * 2;
    }
};