https://leetcode.com/problems/decode-ways/

class Solution {
public:
    vector<int> dp;
    int solve (string s, int i, int n) {
        if(i==n) return 1;
        if(s[i] == '0') return 0;
        if(i == n-1) return 1;
        if(dp[i] != -1) return dp[i];
        string b = s.substr(i, 2);
        int way1 = solve(s, i+1, n);
        int way2 = 0;
        if(b[0]!='0' && stoi(b)<=26 && stoi(b)>0) way2 = solve(s, i+2, n);
        return dp[i] = way1+way2;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        dp = vector<int>(n+1, -1);
        return solve(s, 0, n);
    }
};

// or
