https://leetcode.com/problems/is-graph-bipartite/submissions/
Time : O(V*E) Space : O(V)
class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++) {
            q.push(i);
            if(m.find(i)!=m.end()) continue;
                m[i] = 0;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(auto nei : graph[curr]) {
                       if(m.find(nei)==m.end()) {
                           q.push(nei);
                           m[nei] = (m[curr] == 1) ? 0 : 1;
                       }
                        else if (m[nei] == m[curr]) {
                            return false;
                        }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (int neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
  }
};
