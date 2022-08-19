https://leetcode.com/problems/split-array-into-consecutive-subsequences/submissions/
https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/2446913/C%2B%2B-oror-Greedy-oror-Fully-Commented-oror-Simplest-Solution-Of-All

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;
        for(auto i : nums) freq[i]++;
        for(auto i : nums) {
            if(!freq[i]) continue;
            if(need[i]) {
                need[i]--;
                freq[i]--;
                need[i+1]++;
            } 
            else if(freq[i] && freq[i+1] && freq[i+2]) {
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                need[i+3]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
