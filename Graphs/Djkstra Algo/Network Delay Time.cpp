// Dijkstra
// time : O(ElogV)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto i : times) {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<bool> vis(n+1, false);
        vector<int> dist(n+1, INT_MAX);
        vis[0] = true;
        pq.push({0, k});
        dist[k] = 0;
        int ans = 0;
        while(pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            ans = max(ans, w);
            for(auto [v, weight] : adj[u]) {
                if(vis[v] == false && dist[v] > dist[u]+weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({w+weight, v});
                }
            }
        }
        for(auto i : vis) if(i == false) return -1;
        return ans;
    }
};

// Bellman–Ford
// Time : O(EV)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        for(int i = 1; i<=(n-1); i++) { // repeat v-1 times
            for(auto j : times) {
                int s = j[0], d = j[1], t = j[2];
                if(time[s] != INT_MAX && time[d] > time[s]+t) {
                    time[d] = time[s]+t;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            ans = max(ans, time[i]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
