class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n + 1);
        vector<int> judges(n + 1, 0);
        for(int i = 0; i < trust.size(); i++) {
            graph[trust[i][0]].push_back(trust[i][1]);
            judges[trust[i][1]]++;
        }
        
        for(int i = 1; i <= n; i++)
            if(graph[i].size() == 0 && judges[i] == n - 1) return i;
        return -1;
    }
};