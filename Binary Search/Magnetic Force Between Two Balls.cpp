
https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/


class Solution {
public:
    bool isValid(vector<int> pos, int mxForce, int m) {
        int prev = 0; // we have place 1 ball at 0
        int j = 0, n = pos.size();
        for(int i = 1; i<m; i++) { // now we have to place m-1 such that dis between them is greater than mxForce
            while(j<n && pos[j]<pos[prev]+mxForce) j++;
            if(j>=n) return false; // it is not possible to place m balls such that min dist/force between them is mxForce
            prev = j; // placing ith ball at j
        }
        return true;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int mid = 0, lo = 1, hi = pos[n-1]-pos[0];
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
