https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int count = 0;

        for(int i = 0; i<time.size(); i++) {
            int rem = time[i]%60;
            if(rem == 0) {
                count += mp[0];
            }
            else if(mp.find((60 - rem)%60)!= mp.end()) {
                count += mp[(60 - rem)%60];
            }
            mp[time[i]%60]++;
        }
        return count;
    }
};

// (a + b) % 60 = 0 
// (a % 60 + b % 60) % 60 = 0
// (a % 60 + b % 60)  = 60 
// a % 60  = 60 - b % 60

// we have to find the case of time[i] % 60 == 0 differently


