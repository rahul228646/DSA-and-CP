

// catalan number : https://leetcode.com/problems/unique-binary-search-trees/

// Case 1 : n = 1 Only one combination is possible.

// Case 2 : n = 2 Let fix one node. Two possibilities for second node. It can either be on right or left.
// Hence for n=2 , 2 trees possible

// Case 3: n = 3
// Again fix one node, and we are left with two nodes.
// Possibilities :

// Both are on right
// Both are on left
// One on right and other on left
// Answer to each above case will be Combinations on right X Combinations on left.
// Now we know answer of TWO nodes = 2
// Answer for ONE node is 1
// Answer for THREE nodes : ( ( 2 on right X 0 on left ) + ( 1 on right X 1 on left ) +( 0 on right X 2 on left ) )

// Other CASES :
// SIMILARLY a problem with n nodes can be broken into for n - 1 nodes.

// Array a is created for memomization so that repeated recurcive calls for same value of n are prevented.

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
