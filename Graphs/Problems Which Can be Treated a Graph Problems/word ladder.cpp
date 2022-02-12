// https://leetcode.com/problems/word-ladder/
// Time Complexity = O(n* m * 26)

class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wl) {
        unordered_set<string> dict(wl.begin(), wl.end());
        if(dict.find(end) == dict.end()) return 0;
        queue<string> q;
        q.push(start);
        int ans = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i<n; i++) {
                auto curr = q.front();
                q.pop();
                if(curr == end) return ans;
                for(int j = 0; j<curr.size(); j++) {
                    char c = curr[j];
                    for(int k = 0; k<26; k++) {
                        curr[j] = 'a'+k;
                        if (dict.find(curr) != dict.end()) {
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                    curr[j] = c;
                }
                
            }
            ans++;
        }
        return 0;
    }
};
