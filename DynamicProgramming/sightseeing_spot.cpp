https://leetcode.com/problems/best-sightseeing-pair/submissions/

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, 
minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

we need max val of previously encounters (val + index), since we ass this to every number

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int ans = 0, n = val.size();
        pair<int, int> valIndex = {val[0], 0};
        for(int i = 1; i<n; i++) {
            ans = max(ans, val[i] + valIndex.first + valIndex.second - i);
            if(valIndex.first + valIndex.second <= val[i] + i) {
                valIndex.first = val[i];
                valIndex.second = i;
            }
        }
        return ans;
    }
};
