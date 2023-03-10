class Solution {
public:
    
    bool checkRange(vector<int>& r1, vector<int>& r2) {
        return (r1[0] >= r2[0] && r1[0] <= r2[1]) || (r1[1] >= r2[0] && r1[1] <= r2[1]);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
            else if(newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                newInterval = intervals[i];
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};