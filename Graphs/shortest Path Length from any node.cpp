// https://leetcode.com/problems/shortest-path-visiting-all-nodes/solution/
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/1800180/C%2B%2Bor-Detailed-Explanationor-Answering-WHY-of-each-Question-or-DRY-RUN-or-BFS
// Time : O((2 ^ n) * (n^ 2))

class Solution {
public:
    class tuple {
      public : 
        int node, path, cost;
        tuple(int node, int path, int cost) {
            this->node = node;
            this->path = path;
            this->cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<pair<int, int>> vis;
        queue<tuple> q;
        int all = (1 << n) - 1; 
        
        for(int i = 0; i<n; i++) {
            int path = (1<<i);
            tuple(i, path, 1);
            q.push({i, path, 1}); // we will try to start with all nodes
        }
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(all == curr.path) return curr.cost-1;
            for(auto &adj : graph[curr.node]) {
                int visited_path = curr.path | 1<<adj;
                if(vis.find({adj, visited_path}) == vis.end()) {
                    vis.insert({adj, visited_path});
                    q.push({adj, visited_path, curr.cost+1});
                }
            }
        }
        return -1;
    }
};
