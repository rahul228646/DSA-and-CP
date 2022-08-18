https://leetcode.com/problems/minimum-height-trees

// The idea is that we trim out the leaf nodes layer by layer, until we reach the core of the graph, which are the centroids nodes.

class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    
            return {0};
        vector<int> adj[n];
        vector<int> ans;
        vector<int> in(n, 0);
        queue<int> q;
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
            in[i[1]]++;
        }
        for(int i = 0; i<n; i++) {
            if(in[i] == 1) q.push(i);
        }
        while(q.size()) {
            int sz = q.size();
            ans.clear();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto i : adj[curr]) {
                    in[i]--;
                    if(in[i] == 1) q.push(i);
                }
            }
        }
        return ans;
    }
};
  
