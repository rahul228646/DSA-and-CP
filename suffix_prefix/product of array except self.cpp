https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, 0), suff(n, 0), pre(n, 0);
        int suffProd = 1, preProd = 1;
        for(int i = 0; i<n; i++) {
            suff[i] = suffProd;
            suffProd *= a[i]; 
            pre[n-i-1] = preProd;
            preProd *= a[n-i-1]; 
        }
        for(int i = 0; i<n; i++) {
           ans[i] = suff[i]*pre[i];
        }
        return ans;
    }
};

              1 2 3 4 5 6 7
 suffix -->         |        <-- prefix
              1*2*3   5*6*7
                
                ans for 4 = 1*2*3*5*6*7 (suffix product * prefix product)
