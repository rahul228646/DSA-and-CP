// https://leetcode.com/problems/interval-list-intersections/
// Time : O(n) Space : O(1) if we don't count the space for ans 
class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n = a.size(), m = b.size();
        while(i<n && j<m) {
            if( a[i][1] >= b[j][0] and a[i][0]<=b[j][1]) {
                int low = max(a[i][0], b[j][0]);
                int high = min(a[i][1], b[j][1]);
                ans.push_back({low, high});
            }
            (a[i][1] < b[j][1]) ? i++ : j++; 
        }
        return ans;
    }
};
// all possible cases where intersection happens
// |  |     |  |   |   |   |    |
//   |  |  |  |   |     |   |  |
// if endpoint of a is greater we move ahead in b else er move ahead in a
