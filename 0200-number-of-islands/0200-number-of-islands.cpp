class Solution {
public:
    
    int dirI[4] = {1, -1, 0, 0};
    int dirJ[4] = {0, 0, -1, 1};
    
    bool checkRange(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(vector<vector<char>>& image, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = 1;
        for(int x = 0; x < 4; x++) {
            int newI = i + dirI[x];
            int newJ = j + dirJ[x];
            if(checkRange(newI, newJ, image.size(), image[0].size()) && !vis[newI][newJ] && image[newI][newJ] == '1') {
                dfs(image, vis, newI, newJ);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int numIs = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid[i][j] == '1')
                    numIs++, dfs(grid, vis, i, j);
        
        return numIs;
    }
};