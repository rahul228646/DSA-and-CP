
// https://leetcode.com/contest/biweekly-contest-81/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    long long int dfs(int start, int n, vector<int> adj[], vector<bool> &vis) {
       
        vis[start] = true;
        long long int ans = 0;
        for(auto i : adj[start]) {
            if(!vis[i])
                ans += 1 + dfs(i, n, adj, vis);
        }
        return ans;
        
    }
//   (n - reached) * reached to calculate the number of pairs.
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        long long int pairs = 0, notReached = 0, reached = 0;
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                reached = 1+dfs(i, n, adj, vis);
                notReached = n-reached;
                pairs += (notReached)*reached;
            }
        }
        return pairs/2;
    }
};
