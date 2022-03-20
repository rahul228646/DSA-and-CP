https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
    int minimumJumps(vector<int>& f, int a, int b, int x) {
        int count = 0;
        queue<pair<int, int>> q;
        vector<bool> vis(6000, false);
        unordered_map<int, bool> m;
        bool flag = false;
        for(auto i : f) m[i] = true;
        q.push({0, 0});
        while(!q.empty()) {
           int size = q.size();
            while(size--) {
                auto [curr, back] = q.front();
                q.pop();
                if(curr == x) return count;
                if(vis[curr] || m.find(curr) != m.end()) {
                    continue;
                }
                vis[curr] = true;
                if(back == 0 && curr-b >= 0) q.push({curr-b, 1});
                if(curr+a < 6000) q.push({curr+a, 0});
            }
            // cout<<count<<endl;
            count++;
        }
        return -1;
    }
};


    
