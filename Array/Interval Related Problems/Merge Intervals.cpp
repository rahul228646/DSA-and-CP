https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ivt) {
        int n = ivt.size();
        vector<vector<int>> res;
        sort(ivt.begin(), ivt.end());
        res.push_back(ivt[0]);
        int k = 0;
        for(int i = 1; i<n; i++) {
            int l = ivt[i][0];
            int r = ivt[i][1];
            if(res[k][1] < l) {
                res.push_back(ivt[i]);
                k++;
            }
            else if(res[k][1] < r){
                res[k][1] = r;
            }
        }
        return res;
    }
};
    
// [1 , 3] [2, 6] [8, 10], [15, 18];

// |  |     |  |   |   |   |    |
//   |  |  |  |   |     |   |  |
