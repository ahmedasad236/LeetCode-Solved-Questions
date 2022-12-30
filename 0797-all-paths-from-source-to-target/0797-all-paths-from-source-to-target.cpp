class Solution {
public:
    
    void dfs(int node, int dist, queue<int> path, vector<bool>& vis, vector<vector<int>>& res, const vector<vector<int>>& graph) {
        if(node == dist) {
            vector<int> currPath;
            while(!path.empty()) {
                currPath.push_back(path.front());
                path.pop();
            }
            currPath.push_back(dist);
            res.push_back(currPath);
            return;
        }
        vis[node] = 1;
        path.push(node);
        for(auto ch : graph[node])
            if(!vis[ch]) dfs(ch, dist, path, vis, res, graph);
        vis[node] = 0;
        path.pop();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(), 0);
        vector<vector<int>> res;
        queue<int> path;
        dfs(0, graph.size() - 1, path, vis, res, graph);
        return res;
    }
};