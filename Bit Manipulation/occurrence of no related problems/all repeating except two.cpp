https://leetcode.com/problems/single-number-iii/

class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        
        int Xor = 0;
        for(int i=0;i<nums.size();i++) {
            Xor ^= nums[i];
        }
//     -------------------------------
        int mask = 1;
        while(1) {
            if((mask & Xor) == 0) {
                mask = mask << 1;
            }
            else break;
        }
//       int rmsb = Xor & (-Xor) was not working for -INT_MAX
//     -------------------------------
        int x = 0, y = 0;
        for(int i=0;i<nums.size();i++) {
            if((nums[i] & mask) == 0) {  /
                x ^= nums[i];
            }
            else {
                y ^= nums[i];   
            }
        }
        return { x, y };
        
    }

};
