class Solution {
public:
    
    int dirI[4] = {1, -1, 0, 0};
    int dirJ[4] = {0, 0, -1, 1};
    
    bool checkRange(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis, int sr, int sc, int color) {
        vis[sr][sc] = 1;
        for(int i = 0; i < 4; i++) {
            int newSr = sr + dirI[i];
            int newSc = sc + dirJ[i];
            if(checkRange(newSr, newSc, image.size(), image[0].size()) && !vis[newSr][newSc] && image[newSr][newSc] == image[sr][sc]) {
                dfs(image, vis, newSr, newSc, color);
            }
        }
        
        image[sr][sc] = color;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), 0));
        dfs(image, vis, sr, sc, color);
        return image;
    }
};