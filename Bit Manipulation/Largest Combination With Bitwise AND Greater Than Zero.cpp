// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for(int i = 0; i<32; i++) {
            int setBit = 1<<i;
            int len = 0;
            for(auto candidate : candidates) if(setBit & candidate) len++;
            res = max(res, len);
        }
        return res;
    }
};
