
 vector<pair<int, int>> dir = {
                                    {0, 1}, {1, 0}, {-1, 0}, {0, -1}, 
                                    {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
        
                              };
    int dfs (int i, int j, int n, int m, vector<vector<int>>& g) {
        if(i < 0 || j < 0 || i >= n || j >= m || g[i][j] == -1 || g[i][j] == 0) {
            return 0;
        }
        g[i][j] = -1;
        int ans = 0;
        for(auto k : dir) {
            ans += dfs(i+k.first, j+k.second, n, m, g);
        }
        return ans+1;
    }
    
    int findMaxArea(vector<vector<int>>& g) {
        // Code here
        int ans = 0, n = g.size(), m = g[0].size();
        for(int i= 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if(g[i][j] == 1) {
                    ans = max(ans, dfs(i, j, n, m, g));
                }
            }
        }
        return ans;
    }
