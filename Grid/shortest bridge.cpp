// https://leetcode.com/problems/shortest-bridge/
// using queue<array<int, 3>> q , q.push({x, y, distance}) gives tle
// https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, queue<pair<int, int>>& q) {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        for(auto [x, y] : dir) {
            int newi = x+i, newj = y+j;
            dfs(grid, newi, newj, n, m, q);
        }
        return ;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
      
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {    
                if(grid[i][j] == 1 && q.empty()) {
                    dfs(grid, i, j, n, m, q);
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [i, j] : dir) {
                int ni = i+x, nj = j+y;
                if(ni<n && nj<m && ni>=0 && nj>=0){
                    if(grid[ni][nj] == 1) return grid[x][y]-2;
                    if(grid[ni][nj] == 0){
                        grid[ni][nj] = grid[x][y]+1;
                        q.push({ni, nj});  
                    }
                }
            }
        }
        return -1;
    }
};
