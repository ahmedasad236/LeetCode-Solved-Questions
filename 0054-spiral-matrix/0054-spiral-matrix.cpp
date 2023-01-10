class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        int lastUp = 0, lastLeft = 0, lastDown = n - 1, lastRight = m - 1;
        while(res.size() < n * m) {
            for(int i = lastLeft; i <= lastRight; i++) res.push_back(matrix[lastUp][i]);
            if(res.size() == n * m) break;
            for(int i = lastUp + 1; i <= lastDown; i++) res.push_back(matrix[i][lastRight]);
            if(res.size() == n * m) break;
            for(int i = lastRight - 1; i >= lastLeft; i--) res.push_back(matrix[lastDown][i]);
            if(res.size() == n * m) break;
            for(int i = lastDown - 1; i > lastUp; i--) res.push_back(matrix[i][lastLeft]);
            lastUp++, lastLeft++;
            lastDown--, lastRight--;
        }
        return res;
    }
};