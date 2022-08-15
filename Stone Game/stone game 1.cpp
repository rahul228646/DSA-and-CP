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

// or 

Alice clearly always wins the 2 pile game. With some effort, we can see that she always wins the 4 pile game.

If Alice takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

We can extend this idea to N piles. Say the first, third, fifth, seventh, etc. piles are white, and the second, fourth, sixth, eighth, etc. piles are black. Alice can always take either all white piles or all black piles, and one of the colors must have a sum number of stones larger than the other color.

Hence, Alice always wins the game.
    
class Solution {
public:
   
    bool stoneGame(vector<int>& piles) {
       return true;
    }
};
   
