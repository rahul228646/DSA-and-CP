// topology sort - it return false when there is a cycle 
// Time : O(V+E)
// Space : O(V)

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
            vector<int> adj[n];
            vector<int> in(n, 0), ans;
            for(auto i : pre) adj[i[0]].push_back(i[1]), in[i[1]]++;;
          queue<int> q;
          for(int i = 0; i<n; i++) if(in[i] == 0) q.push(i);
          while(!q.empty()) {
              int curr = q.front();
              q.pop();
              ans.push_back(curr);
              for(auto i : adj[curr]) {
                  in[i]--;
                  if(in[i] == 0) q.push(i);
              }
          }
          return ans.size() == n;
        }
    };
}
