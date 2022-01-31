// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/discuss/1580357/C%2B%2BPython-Clean-and-Simple-Solution-w-Detailed-Explanation-or-Binary-Search-with-Proof
// Time : O(mlogn) Space : O(1)

class Solution {
public:
	// counts number of integers less than or equal to x in multiplication table
    int count(int m, int n, int x) {
        int ans = 0;
        for(int i = 1; i <= m; i++) // for row is [1*i, 2*i, 3*i ... n*i], if we giving x by i this will give the val of column or the number of elements smaller than x in that coumn
            ans += min(x / i, n);
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int L = 1, R = m*n, mid, ans;
        while(L <= R) {
            mid = (L + R) >> 1;
            if(count(m, n, mid) < k) 
                L = mid + 1;
            else
                R = mid - 1, ans = mid;
        }
        return ans;
    }
};
