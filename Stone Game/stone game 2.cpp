class Solution {
public:
    int dp[101][201];
    int solve (vector<int>& p, int m, int n, int i) {
        if(i>=n) return 0;
        int ans = INT_MIN;
        int sum = 0;
        if(dp[i][m] != -1) return dp[i][m];
        for(int j = 0; j<2*m; j++) {
            if(i+j<n)
                sum += p[i+j];
            ans = max(sum- solve(p, max(j+1, m), n, i+j+1), ans);
            dp[i][m] = ans;
        }
        return dp[i][m];
    }
    
    int stoneGameII(vector<int>& p) {
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        for(auto i : p) sum+=i;
        int diff = solve (p, 1, p.size(), 0);
        return (sum+diff)/2;
    }
};

