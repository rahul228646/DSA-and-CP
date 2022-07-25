

vector<vector< int > > dp;
     int solve(int egg, int Floor) {
        if(Floor == 1 || Floor == 0 || egg == 1)
            return Floor;
 
        if(dp[egg][Floor] != -1)
            return dp[egg][Floor];
            
        int ans = INT_MAX, down = 0, up = 0;
        
        for (int i = 1; i <= Floor; ++i) {
            if(dp[egg-1][i-1] != -1)
                down = dp[egg-1][i-1];
            else{
                down = solve(egg-1, i-1);
                dp[egg-1][i-1] = down;
            }
            if(dp[egg][Floor-i] != -1)
                up = dp[egg][Floor-i];
            else {
                up = solve(egg, Floor-i);
                dp[egg][Floor-i] = up;
            }

            ans = min(ans, 1+max(up, down)); // max because we have to check for worst case & min because we have to return minimum no. of ways
        }
        return ans;
    }
    int eggDrop(int egg, int n) {
        dp = vector<vector<int>> (1001, vector<int>(1001, -1));
        return solve(egg, n);
    }
