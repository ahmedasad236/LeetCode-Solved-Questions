class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lastEnd = points[0][1];
        
        int result = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > lastEnd) {
                result++;
                lastEnd = points[i][1];
            }
            lastEnd = min(lastEnd, points[i][1]);
        }
        return result;
        
    }
};