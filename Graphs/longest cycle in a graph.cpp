// https://leetcode.com/contest/weekly-contest-304/problems/longest-cycle-in-a-graph/
class Solution {
public:
    void dfs(int node, int dis, unordered_map<int, int>& mp, vector<int>& vis, vector<int> adj[], int &ans) {
        vis[node] = 1;
        mp[node] = dis;
        for(auto nei : adj[node]) {
            if(vis[nei] == 0) {
                dfs(nei, dis+1, mp, vis, adj, ans);
            }
            else if (mp.find(nei) != mp.end()) {
                ans = max(ans, dis-mp[nei]+1);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++) {
            if(edges[i] != -1) adj[i].push_back(edges[i]); 
        }
        vector<int> vis(n, 0);
        
        int ans = -1;
        for(int i = 0; i<n; i++) {
            unordered_map<int, int> mp;
            dfs(i, 0, mp, vis, adj, ans);
        }
        return ans;
    }
};
