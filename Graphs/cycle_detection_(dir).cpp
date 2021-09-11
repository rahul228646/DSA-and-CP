  
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
