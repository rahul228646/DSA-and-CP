
// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    bool isSpeedValid(vector<int>& piles, int speed, int timeHave) {
        long long timeNeeded = 0;
        for(auto i : piles) {
            timeNeeded += i/speed;
            if(i%speed != 0) timeNeeded++; 
            // if pile is exactle divisible by speed then koko can eat in i/speed time else i/speed + 1
        }
        return  (timeNeeded <= timeHave);
    }
    int minEatingSpeed(vector<int>& piles, int time) {
        int high = 0, low = 1, mid = 0;
        for(auto i : piles) {
            high = max(high, i);
        }
        while(low<high) {
            mid = (low+high)/2;
            if(isSpeedValid(piles, mid, time)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return high;
    }
};
