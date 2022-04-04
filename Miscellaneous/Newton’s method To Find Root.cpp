// https://www.geeksforgeeks.org/find-root-of-a-number-using-newtons-method/
// Time : O(logN)
class Solution {
public:
    int mySqrt(int n) {
        double x = n;
        double root = 0;
        if(n == 0) return 0;
        while(1) {
            root = 0.5*(x+(n/x));
            if(abs(root - x) < 1) break;
            x = root;
        }
        return root;
    }
};
