//https://leetcode.com/problems/arranging-coins/solution/
// time : O(log) space : O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0, r = n;
        long k, curr;
        while(l<=r) {
            k = (l + r)/2;
            curr = k*(k+1)/2;
            if(curr == n) return k;
            if(curr>n) {
                r = k-1;
            }
            else {
                l = k+1;
            }
        }
        return r;
    }
};
