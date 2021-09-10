link : https://leetcode.com/problems/arithmetic-slices/
class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> dp(n, 0);
        for(int i = 2; i<n; i++) {
            if(a[i]-a[i-1] == a[i-1]-a[i-2]) {
                dp[i] = 1+dp[i-1];
            }
            else {
                dp[i] = 0;
            }
            ans += dp[i];
        }
        return ans;
    }
};
