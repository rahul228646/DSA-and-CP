https://www.youtube.com/watch?v=qbQq-k75bcY
class BSF{
  public:
    bool BFS(vector<bool> &visited, vector<int> adj[], int n, int start) {
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(visited[curr]) {
                return true;
            }
            visited[curr] = true;
            for(auto i : adj[curr]) {
                if(!visited[i])
                    q.push(i);
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<bool> visited(V, false);
        // for disconnected components;
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                if(BFS(visited, adj, V, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};


class DFS{
  public:
     bool DFS(int start, vector<bool> &visited, vector<int> adj[], int parent) {
       visited[start] = true;
       for(auto i : adj[start]) {
           if(!visited[i]) {
               if(DFS(i,visited, adj, start)){
                   return true;
               }
           }
           else if(i != parent) {
               return true;
           }
           
       }
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                if(DFS(i,visited, adj, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};







