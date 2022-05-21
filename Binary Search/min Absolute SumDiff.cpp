
// https://leetcode.com/problems/minimum-absolute-sum-difference/submissions/
// https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1966670/C%2B%2B-or-Binary-Search-or-O(nlogn)-or-Easy-to-understand
class Solution {
public:

    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        long long res = 0, sum = 0;
        vector<int> temp = a;
        sort(temp.begin(), temp.end());
        for(int i = 0; i<a.size(); i++) sum += abs(a[i]-b[i]);
        res = sum;
        for(int i = 0; i<a.size(); i++) {
            sum -=  abs(a[i]-b[i]);
            int idx = lower_bound(temp.begin(), temp.end(), b[i]) - temp.begin(); // find an element in a/temp which is closest to b[i] 
            if(idx >= a.size()) idx = a.size()-1; 
            if(idx > 0 && temp[idx] != b[i]) res = min(res, sum+abs(temp[idx-1]-b[i])); // since we are using lower bound so prev elemtemt could be closest eg =  {1, 2, 5, 6} lower bound of 3 gives 5 but 2 is closer
            res = min(res, sum+abs(temp[idx]-b[i]));
            sum +=  abs(a[i]-b[i]);
        }
        return res % (1000000007);
    }
};

