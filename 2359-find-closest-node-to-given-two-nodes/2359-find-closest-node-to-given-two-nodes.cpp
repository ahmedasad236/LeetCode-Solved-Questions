class Solution {
public:
    
    void dijkstra(int start, vector<int>& edges, vector<int>& distances) {
        distances[start] = 0;
        queue<int> q;
        q.push(start);
        vector<bool> vis(edges.size(), 0);
        vis[start] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(edges[curr] != -1 && !vis[edges[curr]]) {
                vis[edges[curr]] = 1;
                distances[edges[curr]] = 1 + distances[curr];
                q.push(edges[curr]);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> distances1(edges.size(), -1);
        vector<int> distances2(edges.size(), -1);
        dijkstra(node1, edges, distances1);
        dijkstra(node2, edges, distances2);
        
        int mnDistance = 1e9, res = -1;
        for(int i = 0, n = distances1.size(); i < n; i++) {
            if(distances1[i] != -1 && distances2[i] != -1) {
                int mxDist = max(distances1[i], distances2[i]);
                if(mxDist < mnDistance) {
                    mnDistance = mxDist;
                    res = i;
                }
            }
            // cout << "dist1 = " << distances1[i] << '\n';
            // cout << "dist2 = " << distances2[i] << '\n';
        }
        return res;
        
    }
};