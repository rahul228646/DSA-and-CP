// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ivt) {
        int n = ivt.size();
        sort(ivt.begin(), ivt.end()); // sort invertals in increasing order of left (start interval)
        int lI = ivt[0][0], rI = ivt[0][1], cnt = 0;
        for(int i = 1; i<n; i++) {
            if(ivt[i][0]>=rI) {     //     |  |      |   |      --- 2 cases of overlap (in both right of first ivt is smaller than left of second)
                                    //       |  |     | |
                lI = ivt[i][0];
                rI = ivt[i][1];
            }
            else {
                rI = min(ivt[i][1], rI);  // we have to remove the interval which has greater right value
                cnt++;
            }
        }
        return cnt;
    }
};
