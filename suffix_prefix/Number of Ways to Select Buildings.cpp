// Number of Ways to Select Buildings
// https://leetcode.com/problems/number-of-ways-to-select-buildings/
class Solution {
public:
    long long numberOfWays(string s) {
        int oneCount = 0, zeroCount = 0;
        for(auto i : s) if(i == '1') oneCount++; else zeroCount++;
        int oneBeforeZero = 0, zeroBeforeOne = 0;
        long long ans = 0;
        for(auto i : s) {
            if(i == '1') {
                ans += zeroBeforeOne * zeroCount; // zeroCount == zeroAfterOne
                oneCount--;
                oneBeforeZero++;
            }
            else {
                ans += oneBeforeZero * oneCount; // oneCount == oneAfterZero
                zeroCount--;
                zeroBeforeOne++;
            }
        }
        return ans;
    }
};
