
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size(), maxReachSoFar = 0, end = 0, count = 0;
        sort(clips.begin(), clips.end());
        // if(clips[n-1][1] < time) return -1;
        for(int i = 0; i<n && end<time; end = maxReachSoFar) {
            count++;
            while(i<n && clips[i][0] <= end) {
                maxReachSoFar = max(maxReachSoFar, clips[i++][1]);
            }
            if(end == maxReachSoFar) return -1;
        }
        if(maxReachSoFar < time) return -1;
        return count;
    }
};

// [0, 2] [3, 4]
// time = 4
// ans = -1
