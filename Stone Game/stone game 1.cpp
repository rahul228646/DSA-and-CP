https://leetcode.com/problems/stone-game/submissions/
class Solution {
public:
    int solve (vector<int>& piles, int i , int j, vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i == j) return dp[i][j] = piles[i];
        
        int front = piles[i] + min(solve(piles, i+2, j, dp), solve(piles, i+1, j-1, dp)); //as oponent will leave us with minimun piles in hist turn
        int back = piles[j] + min(solve(piles, i+1, j-1, dp), solve(piles, i, j-2, dp));
        return dp[i][j] = max(front, back); // doing our best
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), sum = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(auto i : piles) sum += i;
        // cout<<solve(piles, 0, n-1)<<endl;
        return solve(piles, 0, n-1, dp) > sum/2;
    }
};

