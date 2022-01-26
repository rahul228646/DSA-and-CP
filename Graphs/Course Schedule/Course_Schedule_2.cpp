// Topology sort
 
// time - O(V+E)
// Space - O(V)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        vector<int> bsf;
        
        for(auto i : pre) adj[i[0]].push_back(i[1]), inDegree[i[1]]++;
        
        for(int i = 0; i<n; i++) if(inDegree[i] == 0) bsf.push_back(i);
        
        for(int i = 0; i<bsf.size(); i++) {
            for(auto i : adj[bsf[i]] ) {
                inDegree[i]--;
                if(inDegree[i] == 0) bsf.push_back(i);
            }
        }
        reverse(bsf.begin(), bsf.end());
        (bsf.size()==n) ? bsf = bsf : bsf = {};
        return bsf;
    }
};

or 
 
// time - O(V+E)
// Space - O(V)
class Solution {
public:
    vector<int> topoSortBFS(int V, vector<int> adj[]) {
          vector<int> in(V, 0), ans;
          for(int i = 0; i<V; i++) {
              for(auto j : adj[i]) {
                  in[j]++;
              }
          }
          queue<int> q;
          for(int i = 0; i<V; i++) {
              if(in[i] == 0) q.push(i);
          }
          while(!q.empty()) {
              int curr = q.front();
              q.pop();
              ans.push_back(curr);
              for(auto i : adj[curr]) {
                  in[i]--;
                  if(in[i] == 0) q.push(i);
              }
          }
          return ans;
    }
};
