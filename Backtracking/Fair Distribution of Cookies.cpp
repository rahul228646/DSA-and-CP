// https://leetcode.com/contest/weekly-contest-297/problems/fair-distribution-of-cookies/
// Time : O(k^n) Space : O(n)

class Solution {
public:
    int helper(vector<int>& c, vector<int>& child, int idx, int k, int n) {
        if(idx == n) {
            int mx = INT_MIN;
            for(int i = 0; i<k; i++) {
                mx = max(mx, child[i]);
            }
            return mx;
        }
        int ans = INT_MAX;
        for(int i = 0; i<k; i++) {
            child[i]+=c[idx];
            ans = min(ans, helper(c, child, idx+1, k, n));
            child[i]-=c[idx];
        }
        return ans;
    }
    int distributeCookies(vector<int>& c, int k) {
        vector<int> child (k, 0);
        return helper(c, child, 0, k, c.size());
    }
};
