// Time : O(V+E)
// Space : O(V)

// dfs for Directed Graph
class Solution {
public:
    bool dfsIsCycle(int n, vector<int> adj[], vector<bool>& visited, vector<bool>& stack, int curr) {
        if(!visited[curr]) {
            visited[curr] = true;
            stack[curr] = true;
            for(auto i : adj[curr]) {
                if(!visited[i] && dfsIsCycle(n, adj, visited, stack, i)) return true;
                else if(stack[i]) return true;
            }
        }
        stack[curr] = false;
        return false;
    } 
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<bool> visited(n, false);
        vector<bool> stack(n, false);
        for(auto i : pre) {
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                if(dfsIsCycle(n, adj, visited, stack, i)) return false;
            }
        }
        return true;
    }
};

we first start with a node and put all the nodes connected to it that are not visited and the call the function on those stacked nodes and 
is we find a node that is already visited and present in the stack then a cycle exists and we return else we backtrack and remove nodes from stack
after all are visited we return false
5
[[1->4],[2->3,4],[3->1],[3->2],[4->3]]
