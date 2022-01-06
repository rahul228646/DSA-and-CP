https://leetcode.com/problems/word-break/submissions/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        
        dp[0] = true;
        for(int i = 1; i<=n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(dp[j]) {
                    string word = s.substr(j, i-j);
                    if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        // cout<<i<<endl;
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n]; 
// sice no char of the string should be used, therefore at the end we will get true, if the string can be divided
    }
};

