// https://www.youtube.com/watch?v=R3AJoOBVAlg&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int ogColor, int n, int m) {

        grid[i][j] = -1*ogColor;
        int count = 0;
        for(auto [x, y] : dir) {
            int nwi = x+i, nwj = y+j;
            if(nwi<0 || nwj<0 || nwi>=n || nwj>=m || abs(grid[nwi][nwj]) != ogColor) continue;
            count++;
            if(grid[nwi][nwj] == ogColor) dfs(grid, nwi, nwj, ogColor, n, m);
        }
        if(count == 4) grid[i][j] = ogColor;
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        int ogColor = grid[row][col];
        dfs(grid, row, col, ogColor, n, m);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == -1*ogColor) {

                    grid[i][j] = color; 
                }
            }
        }
        return grid;
    }
};
