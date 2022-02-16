// for -ve edge cycle detection
// Time : O(EV)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        for(int i = 1; i<=(n-1); i++) { // repeat v-1 times to find shortest distance/time  to all vertices
            for(auto j : times) {
                int s = j[0], d = j[1], t = j[2];
                if(time[s] != INT_MAX && time[d] > time[s]+t) {
                    time[d] = time[s]+t;
                }
            }
        }
      
        for(auto j : times) { // repeat one more time , if distances/time are updated here , then this indicates a -ve cycles (adding -ve weights will decrease time. dist)
            int s = j[0], d = j[1], t = j[2];
            if(time[d] > time[s]+t) {
              cout<<"_ve weight cycle detected";
              return -1;
            }
         }
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            ans = max(ans, time[i]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
