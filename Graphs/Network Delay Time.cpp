// Dijkstra
// time : O(ElogV)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited (n+1, false);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<pair<int, int>> adj[n+1];
        for(int i = 0; i<times.size(); i++) {
            auto s = times[i][0], d = times[i][1], t = times[i][2];
            adj[s].push_back({t, d});
        }
        int time = -1;
        for(auto i : adj[k]) {
            auto [t, d] = i;
            pq.push({t, d});
        }
        
        visited[k] = true;
        while(!pq.empty()) {
            auto [t, d] = pq.top();
            pq.pop();
            if(!visited[d]) {
                time = max(time, t);
                visited[d] = true;
                for(auto i : adj[d]) {
                    auto [t_2, d_2] = i;
                    pq.push({t_2+t, d_2});
                }
            }
        }
        for(int i = 1; i<=n; i++) {
            if(!visited[i]) return -1;
        }
        return time;
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
