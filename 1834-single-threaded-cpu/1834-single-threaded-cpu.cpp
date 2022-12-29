class Solution {
public:


    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        for(int i = 0; i < tasks.size(); i++)
            v.push_back({tasks[i][0], tasks[i][1], i});
        sort(v.begin(), v.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        long long time = v[0][0];
        int i = 0, n = tasks.size();
        while(i < n || !pq.empty()) {
            while(i < n && time >= v[i][0]) {
                pq.push({v[i][1], v[i][2]});
                i++;
            }
            
            pair<int, int> top = pq.top();
            ans.push_back(top.second);
            time += top.first;
            pq.pop();
            if(pq.empty() && i < n && time < v[i][0])
                time = v[i][0];
        }
        
        return ans;
        
    }
};