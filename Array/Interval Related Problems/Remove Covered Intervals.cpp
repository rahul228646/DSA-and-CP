// https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivt) {
        int n = ivt.size();
        sort(ivt.begin(), ivt.end());
        int ans = 0, l = -1, r = -1;
        for(auto i : ivt) {
            if(i[0] > l && i[1] > r) {
                ans++;
                l = i[0];
            }
            r = max(r, i[1]);
        }
        return ans;
    }
};

