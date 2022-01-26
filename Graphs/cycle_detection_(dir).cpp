  
class Dfs{
  public:
  bool DFS (vector<int> adj[], vector<bool> &visited, vector<bool> &reStack, int start) {
        if(!visited[start]) {
            visited[start] = true;
            reStack[start] = true;
            for(auto i : adj[start]) {
                if(!visited[i] && DFS(adj, visited, reStack, i)) {
                    return true;
                }
                else if (reStack[i]) {
                    return true;
                }
            }
        }
        reStack[start] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        // to find a node already present in the stack
        vector<bool> reStack(V, false);
        for(int i = 0; i<V; i++) {
            if(!visited[i])
                if(DFS(adj, visited, reStack, i)) {
                        return true;
                }
        }
        return false;
    }
};


we first start with a node and put all the nodes connected to it that are not visited and the call the function on those stacked nodes and 
is we find a node that is already visited and present in the stack then a cycle exists and we return else we backtrack and remove nodes from stack
after all are visited we return false
5
[[1->4],[2->3,4],[3->1],[3->2],[4->3]]
  
  
