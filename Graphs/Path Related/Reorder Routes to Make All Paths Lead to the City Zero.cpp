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

