// https://leetcode.com/problems/keys-and-rooms/submissions/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int start, vector<bool> &vis) {
        vis[start] = true;
        for(int i = 0; i<graph[start].size(); i++) {
            if(!vis[graph[start][i]])
                dfs(graph, graph[start][i], vis);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(int i = 0; i<n; i++) if(!vis[i]) return false;
        return true;
    }
};
