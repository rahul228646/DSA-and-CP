https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &vis, int from) {
        auto change = 0;
        vis[from] = true;
        for (auto to : adj[from])
            if (!vis[abs(to)])
                change += dfs(adj, vis, abs(to)) + (to > 0);
        return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (auto &c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        
        return dfs(adj, vis, 0);
    }
};



class Solution {
public:
    int bfs(int n, vector<int>adj[], int start, vector<bool> &vis) {
        queue<int> q;
        q.push(start);
        bool flag = false;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(vis[curr]) {
                    flag = true;
                    continue;
                }
                vis[curr] = true;
                for(auto i : adj[curr]) {
                    q.push(i);
                }
            }
        }
        if(flag) return 1;
        return 0;
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        int ans = 0;
        for(auto i : c) {
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                ans += bfs(n, adj, i, vis);
            }
        }
        return ans;
    }
};

