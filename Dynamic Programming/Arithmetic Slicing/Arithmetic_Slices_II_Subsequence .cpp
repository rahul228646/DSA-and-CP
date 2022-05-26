leetcode : https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3970/
youtube  : https://www.youtube.com/watch?v=XjLT4TaXsgw

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<unordered_map<int, int>> dp(n);
        for(int i = 1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if((long)a[i] - (long)a[j] > INT_MAX || (long)a[i] - (long)a[j] < INT_MIN) 
                  continue;
                int diff = a[i]-a[j];
                dp[i][diff] += 1;
                if(dp[j].find(diff) != dp[j].end()) {
                    ans += dp[j][diff]; 
                    dp[i][diff] += dp[j][diff];
                }
                

            }
        }
        return ans;
    }
    };
