// https://leetcode.com/problems/get-equal-substrings-within-budget/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int j = 0, n = s.length(), i = 0, ans = 0;
        for(; j<n; j++) {
            cost += abs(s[j]-t[j]);
            while(cost>maxCost) {
                cost -= abs(s[i]-t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
