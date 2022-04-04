// https://leetcode.com/problems/number-of-ways-to-select-buildings/
// gives tle
class Solution {
public:
    long long dp[1000000][3][4]; // n - (0, 10^5), prev - (0, 1, 2(initially)), size - (0, 1, 2, 3)
    
    long long solve (string s, char prev, int n, int size) {
        if(size == 3) return 1;
        if(n == 0) return 0;
        if(dp[n][prev-'0'][size] != -1) return dp[n][prev-'0'][size];
        long long  op1 = 0;
        if(s[n-1] != prev) {
            op1 = solve(s, s[n-1], n-1, size+1);
        }
        long long op2 = solve(s, prev, n-1, size);  
        return dp[n][prev-'0'][size] = op1 + op2;
    }
    
    long long numberOfWays(string s) {
        memset(dp,-1, sizeof dp);
        return solve(s, '2', s.length(), 0);
    }
};


// https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907026/Easy-understanding-C%2B%2B-code-with-comments

class Solution {
public:
    long long numberOfWays(string s) {
        int oneCount = 0, zeroCount = 0;
        for(auto i : s) if(i == '1') oneCount++; else zeroCount++;
        int oneBeforeZero = 0, zeroBeforeOne = 0;
        long long ans = 0;
        for(auto i : s) {
            if(i == '1') {
                ans += zeroBeforeOne * zeroCount; // zeroCount == zeroAfterOne
                oneCount--;
                oneBeforeZero++;
            }
            else {
                ans += oneBeforeZero * oneCount; // oneCount == oneAfterZero
                zeroCount--;
                zeroBeforeOne++;
            }
        }
        return ans;
    }
};
