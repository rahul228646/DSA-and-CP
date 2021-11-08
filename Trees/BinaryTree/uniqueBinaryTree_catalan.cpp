

// catalan number : https://leetcode.com/problems/unique-binary-search-trees/

// T(i) = summation 0 : i-1 T(j) * T(i-j-1)
// Time : O(n) Space : O(n)

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = 0;
            for(int j = 0; j<i; j++) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

// T(n) = 1/(n+1) * C(2n,n)
// Time : O(n) Space : O(1)

class Solution {
public:
  
//   C(n, k) 
// = n! / (n-k)! * k!
// = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) * 
//                             ( k * (k-1) * .... * 1 ) ]
// After simplifying, we get
// C(n, k) 
// = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

// Also, C(n, k) = C(n, n-k)  
// r can be changed to n-r if r > n-r 
  
    long long binomialCoeff(int n, int k) {
        if(k == 0 || k == n) return 1;
        long long res = 1;
        if(k > n-k) k=n-k;
        for(int i = 0; i<k; i++) {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    int numTrees(int n) {
        long long c = binomialCoeff(2*n, n);
        return c/(n+1);
    }
};
