
// Time : O(n) Space : O(n)
// https://www.geeksforgeeks.org/friends-pairing-problem/

    int countFriendsPairings(int n) 
    { 
        long long dp[n + 1];
    
        for (long long i = 0; i <= n; i++) {
            if (i <= 2)
                dp[i] = i;
            else
                dp[i] =( dp[i - 1] + ( (i - 1) * dp[i - 2]) );
        }
        return dp[n]
    }

// For n-th person there are two choices:
// 1) n-th person remains single, we recur 
//    for f(n - 1)
// 2) n-th person pairs up with any of the 
//    remaining n - 1 persons. We get (n - 1) * f(n - 2)
