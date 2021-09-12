
Time: O(V^2)
Space: O(V)
// adj[u] is vector with v source and w weight
class Prim1{
  public:
  	int findNodeWithMinKey(vector<bool> setMst, vector<int> key, int V) {
        int min = INT_MAX, min_index;
     
        for (int v = 0; v < V; v++)
            if (setMst[v] == false && key[v] < min)
                min = key[v], min_index = v;
     
        return min_index;
	  }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int> parent(V, -1), key(V, INT_MAX);
        vector<bool> setMst(V, false);
        key[0] = 0;
        // since mst has v-1 edges
        for(int i = 0; i<V-1; i++) {
            int u = findNodeWithMinKey(setMst, key, V);
            setMst[u] = true;
            for(auto v : adj[u]) {
                if((v[0]) && (setMst[v[0]] == false) && (v[1]<key[v[0]])) {
                    parent[v[0]] = u, key[v[0]] = v[1];
                }
            }
        }
        int sum = 0;
        for(int i = 0; i<V; i++) {
            sum += key[i];
        }
        return sum;
    }
};
