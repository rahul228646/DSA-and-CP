// https://leetcode.com/problems/number-of-excellent-pairs/submissions/

// setBits(BITWISE AND of x,y) + setBits(BITWISE OR of x,y) = setBits(x) + setBits(y)

// Explanation:
// Let setBits in x = a, setBits in y = b
// Bitwise AND represents setBits common in x and y. Let setBits in (x&y) = c
// Bitwise OR represents setBits which are either in x or y. So setBits in (x|y) = (setBits in x) + (setBits in y) - common setBits = a+b-c
// Therefore, setBits(BITWISE AND of x,y) + setBits(BITWISE OR of x,y) = c + (a+b-c) = (a+b) = setBits(x) + setBits(y).
  
  
class Solution {
public:
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set s(nums.begin(), nums.end()); // to remove duplicates
        vector<int> setBits;
        for(auto i : s) {
            setBits.push_back(__builtin_popcount(i));
        }
        sort(setBits.begin(), setBits.end());
        long long count = 0;
        for(int i = 0; i<setBits.size(); i++) {
            int idx = lower_bound(setBits.begin(), setBits.end(), k-setBits[i]) - setBits.begin();
            count += setBits.size()-idx;
        }
        return count;
    }
};
