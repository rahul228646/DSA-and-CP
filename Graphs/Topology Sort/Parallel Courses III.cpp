https://leetcode.com/problems/parallel-courses-iii/submissions/
Time : O(N) Space : O(N)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n, 0), completionTime(n, 0), startTime(n, 0);
        vector<int> adj[n];
	    for(auto i : relations) {
            adj[i[0]-1].push_back(i[1]-1);
            in[i[1]-1]++;
        }
	    queue<int> q;
	    for(int i = 0; i<n; i++) {
	        if(in[i] == 0) q.push(i); // course and startTime;
	    }
        
	    while(!q.empty()) {
	        int sz = q.size();
  
            while(sz--) {
                auto course = q.front();
                q.pop();
                completionTime[course] = startTime[course] + time[course];
                for(auto nxt : adj[course]) {
                    in[nxt]--;
                    startTime[nxt] = max(completionTime[course], startTime[nxt]);
                    if(in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
            
	    }
        int ans = 0;
        for(auto i : completionTime) ans = max(ans, i);
	    return ans;
    }
};
