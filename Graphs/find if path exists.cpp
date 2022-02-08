https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool validPath(int n, vector<int> adj[], int source, int destination, vector<bool>& visited) {
        if(source == destination) return true;
        if(visited[source]) return false;
        visited[source] = true;
        for(auto i : adj[source]) {
            if(validPath(n, adj, i, destination, visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return validPath (n, adj, source, destination, visited);
    }
};
