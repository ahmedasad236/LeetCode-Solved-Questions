#define ippair pair<int, pair<int, int>>
class Solution {
public:
    
    int dijkstra(int src, int dst, int k, int n, vector<vector<pair<int, int>>>& graph) {
        
        vector<int> dist(n, 1e9);
        queue<pair<int, int>> q;
        dist[src] = 0;
        q.push({src, 0});
        int stops = 0;
        while(stops <= k && !q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front().first;
                int distance = q.front().second;
                q.pop();
                for(auto ch : graph[node]) {
                    int price = ch.second;
                    int neighbour = ch.first;
                    if(price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < flights.size(); i++) {
            int s = flights[i][0], d = flights[i][1], w = flights[i][2];
            graph[s].push_back({d, w});
        }
        return dijkstra(src, dst, k, n, graph);
    }
};