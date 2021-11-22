
// Time : O(n^2) Space : O(n^2)
// similar to lis;
class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return n;
        vector<unordered_map<int, int>> diff(n);
        int mx = 2; // 2 because  min size of any ap will be 2;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                int d = arr[i]-arr[j];
                diff[i][d] = (diff[j].count(d)>0) ? diff[j][d]+1 : 2; // 2 because  min size of any ap will be 2;
                mx = max(mx, diff[i][d]);
            }
        }
        return mx;
    }
};
