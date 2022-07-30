https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/506853/Java-A-general-greedy-solution-to-process-similar-problems
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n, 0);
        for(int i = 0; i < ranges.size(); i++) {
            if(ranges[i] == 0) continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }
		
		// same part like previous problem
        int end = 0, farCanReach = 0, cnt = 0;        
        for(int i = 0; i < arr.size() && end < n; end = farCanReach) {
            cnt++;
            while(i < arr.size() && i <= end) {
                farCanReach = max(farCanReach, arr[i++]);                            
            }
            if(end == farCanReach) return -1; 
        }
        return cnt;
    }
};
