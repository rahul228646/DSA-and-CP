https://leetcode.com/problems/maximum-running-time-of-n-computers/

class Solution {
public:

    // The idea is to check if we can run computers for m min (n * m total min). 
    For that, we accumulate power from all batteries, taking no more than m from each. 
    If we have enough power for n * m min - we can run all our computers for m min. (m == time)
    
    bool isValidTime(int n, long long time, vector<int>& batteries) {
        long long totalChargeNeed = n*time;
        long long totalChargeWeHaveToRunForAtLeastT = 0;
        for(auto i : batteries) {
            totalChargeWeHaveToRunForAtLeastT += min((long long)i, time);
        }
        return totalChargeWeHaveToRunForAtLeastT >= totalChargeNeed;
    }
    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = 0;
        sort(batteries.begin(), batteries.end(), greater<int>());
        for(auto i : batteries) sum+=i;
        long long low = 0, high = sum/n, mid = 0;
        
        while(low<high) {
            mid = (low +high+1)/2;
            if(isValidTime(n, mid, batteries)) {
                low = mid; 
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};
