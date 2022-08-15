// We just calculate the net max difference possible. Now let the amount collected by Alex be 'a' and by Lee be 'b'.
// a+b = Total sum of piles
// a-b = MaxDiff
// So a = (Total+MaxDiff)/2
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

class Solution {
public:
    int helper(vector<int> piles, int m, int idx, bool aliceTurn, vector<vector<vector<int>>>& dp) {
        
        if(idx >= piles.size()) return 0;
        
        if(dp[idx][m][aliceTurn] != -1) return dp[idx][m][aliceTurn];
        
        if(aliceTurn) {     // When its Alice's turn she will try to maximize her count of stones. 
            int ans = 0, sum = 0;   
            for(int i=idx; (i-idx) < 2*m && i < piles.size(); i++) {
                sum += piles[i];
                ans = max(ans, sum + helper(piles, max((i-idx)+1, m), i+1, !aliceTurn, dp));
            }
            dp[idx][m][aliceTurn] = ans;
        } 
        else {        // When its Bob's turn he just makes sure Alice gets the minimum possible stones.
            int ans = INT_MAX;
            for(int i=idx;(i-idx) < 2*m && i < piles.size(); i++) {
                ans = min(ans, helper(piles, max((i-idx)+1, m), i+1, !aliceTurn, dp)); 
            }
            dp[idx][m][aliceTurn] = ans;
        }
        
        return dp[idx][m][aliceTurn];
    }
    int stoneGameII(vector<int>& piles) {
        int sz = piles.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(2*sz, vector<int>(2, -1)));
        return helper(piles, 1, 0, true, dp);
    }
};
