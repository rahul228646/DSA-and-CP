
https://leetcode.com/problems/open-the-lock/submissions/


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> d;
        for(auto i : deadends) d[i] = true;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while(q.size()) {
            auto [c, t] = q.front();
            q.pop();
            if(d.find(c) != d.end()) continue;
            if(c == target) return t;
            d[c] = true;
            for(int i = 0; i<4; i++) {
                string t1 = c, t2 = c;
                t1[i] = '0' + (t1[i]+1-'0') % 10;
                t2[i] = '0' + (t2[i]-1-'0'+10) % 10;
                if(d.find(t1) == d.end()) {
                    q.push({t1, t+1});
                }
                if(d.find(t2) == d.end()) {
                    q.push({t2, t+1});
                }
            
            }
        }
        return -1;
    }
};
