// https://leetcode.com/problems/perfect-squares/
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0) return 0;
        
        // dp[i] = the least number of perfect square numbers 
        // which sum to i. Note that dp[0] is 0.
        vector<int> dp(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++){
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return cntPerfectSquares[n];
    }
};


// 1 2 3 4 5 6 7 8 9 10 11 12 
// 1 2 3 1 2 3 4 2 1 2  3  3 
    
   
