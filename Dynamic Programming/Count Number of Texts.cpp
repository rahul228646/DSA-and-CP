https://leetcode.com/problems/count-number-of-texts/

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dp;
    long long int solve(int i, int n, string s) {
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        long long int count = 0;
        if(i+3<n && (s[i] == '7' || s[i] == '9') && s[i] == s[i+1] && s[i] == s[i+2] && s[i] == s[i+3]) count = count % MOD + solve(i+4, n, s) % MOD;
        if(i+2<n && s[i] == s[i+1] && s[i] == s[i+2]) count = count % MOD + solve(i+3, n, s) % MOD;
        if(i+1<n && s[i] == s[i+1]) count = count % MOD + solve(i+2, n, s) % MOD;
        return dp[i] = count % MOD + solve(i+1, n, s) % MOD;
        
    }
    int countTexts(string keys) {
        int n = keys.length();
        dp.resize(n, -1);
        return solve(0, n, keys)% MOD;
    }
};

class Solution {
public:
    int MOD = 1e9 + 7;
      int countTexts(string s) {
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i = 1; i<=s.size(); ++i)
        {
            dp[i] =( dp[i]+dp[i-1])%MOD;
            if(i-2>=0 && s[i-1]==s[i-2]) {
                dp[i] = (dp[i]+dp[i-2])%MOD;
                if(i-3>=0 && s[i-1]==s[i-3])
                {
                    dp[i] = (dp[i] + dp[i-3])%MOD;
                    if(i-4>=0 && (s[i-1]=='7'||s[i-1]=='9') && s[i-1]==s[i-4])
                        dp[i] = (dp[i]+dp[i-4])%MOD;
                }
            }
        }
        return dp.back();
    }
};
