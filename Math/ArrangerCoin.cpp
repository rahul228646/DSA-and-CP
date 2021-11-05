// https://leetcode.com/problems/arranging-coins/solution/
// time : O(1) space : O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        // x(x+1)/2 = y (y is placs to keep coins, x is stairs)
        // x(x+1)/2 <= y (acc to problem y can be more than no of coins)
        // x(x+1) <= 2y
        // x^2 + x <= 2y
        // x^2 + x 1/4 - 1/4 <= 2y
        // (x+1/2)^2 <= 2y + 1/4
        // x = (2y + 1/4)^1/2 - 1/2
        return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};
