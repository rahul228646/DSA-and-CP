https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10
https://leetcode.com/explore/featured/card/recursion-i/253/conclusion/1675/

class Solution {
public:

    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) {
            return 0;
        }
        int mid = pow(2, n-1)/2;
        if(k<=mid) {
            return kthGrammar(n-1, k);
        }
        else {
            return !kthGrammar(n-1, k-mid);
        }
    }
};

length is 2^(n-1) // for k <= mid all elements of n are copy of n-1 row ans for k > mid kth element of nth row is complement of k-mid th element of n-1 th row
n = 1 -> 0
n = 2 -> 0 1   
n = 3 -> 0 1 1 0
n = 4 -> 0 1 1 0 1 0 0 1   
