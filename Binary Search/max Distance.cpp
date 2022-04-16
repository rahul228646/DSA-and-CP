// https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794103/C%2B%2B-Binary-Search-with-explanation-(with-other-binary-answer-problems
// https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/

// Time: O(log(max(A)) * N + NlogN)
// Space: O(1)

class Solution {
public:
    bool isValid(vector<int>& pos, int mxForce, int m) {
        int prev = 0, n = pos.size(), j = 1; // place 1st ball on 0th pos
        for(int i = 1; i<m; i++) {
            while(j<n && pos[j] < pos[prev]+mxForce) j++; // try to place m-1 ball such that distance between the is at least mxForce
            if(j>=n) return false;
            prev = j;
        }
        return true;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int lo = 1, hi = pos[pos.size()-1]-pos[0]; // range of valid ans
        int mid = 0;
        while(lo<=hi) {
            mid = (lo+hi)/2;
            if(isValid(pos, mid, m)) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return hi;
    }
};
