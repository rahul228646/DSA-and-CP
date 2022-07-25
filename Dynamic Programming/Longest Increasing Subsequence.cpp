
https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
       int n = arr.size();
       vector<int> dp(n, 1), count(n,1);
       int mx = 0;
       for(int i = 0; i<n; i++) {
           for(int j = 0; j<i; j++) {
               if(arr[j]<arr[i] && dp[j] + 1 > dp[i]) {
                   dp[i] = dp[j]+1;
                   count[i] = count[j];
               }
               else if(arr[j]<arr[i] && dp[j] + 1 == dp[i]) {
                   count[i] += count[j];
               }
           }
           mx = max(mx, dp[i]);
       }
        // cout<<mx<<endl;
        int res = 0;
        for(int i = 0; i<n; i++) {
            if(dp[i] == mx) {
                res+=count[i];
            }
        }
        return res;
    }
};

