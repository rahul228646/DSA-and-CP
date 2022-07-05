https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/DFS-on-upscaled-grid
https://leetcode.com/problems/regions-cut-by-slashes/submissions/

class Solution {
public:
    int dfs(vector<vector<int>> &g, int i, int j) {
        if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 1)
            return 0;
        g[i][j] = 0;
        return 1 + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j - 1) + dfs(g, i, j + 1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> dfsGrid(n*3, vector<int>(n*3, 1));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '/')  {
                    dfsGrid[i*3][j*3+2] = dfsGrid[i*3+1][j*3+1] = dfsGrid[i*3+2][j*3] = 0;
                }
                else if(grid[i][j] == '\\') {
                    dfsGrid[i*3][j*3] = dfsGrid[i*3+1][j*3+1] = dfsGrid[i*3+2][j*3+2] = 0;
                }
            }
        }
        // for(auto i : dfsGrid) {
        //     for(auto j : i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int regions = 0;
         for (int i = 0; i < n * 3; ++i)
        for (int j = 0; j < n * 3; ++j)
            regions += dfs(dfsGrid, i, j) ? 1 : 0;    
    return regions;

    }
};
