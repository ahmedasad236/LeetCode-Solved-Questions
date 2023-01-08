class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int mx = 1;

        for(int i = 0; i < points.size(); i++) {
            unordered_map<double, int> slopes;

            for(int j = 0; j < points.size(); j++) {
                if(i == j) continue;
                
                double slope = (points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]);
                double angle = atan(slope);
                slopes[angle]++;
                mx = max(mx, slopes[angle] + 1);
            }
        }

        return mx;
    }
};