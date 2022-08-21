// https://leetcode.com/problems/minimum-window-substring/
// Time : O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, string> ans = {INT_MAX, ""};
        unordered_map<char, int> mp;
        for(auto i: t) mp[i]++;
        int i = 0, j = 0, n = s.length(), count = mp.size();
        
        for(;j<n;j++) {
            if(mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            while(count == 0) {
                if(ans.first>j-i+1) {
                    ans.first = j-i+1;
                    ans.second = s.substr(i, j-i+1);
                }
                if(mp.count(s[i])) {
                    if(mp[s[i]] == 0) count++;
                    mp[s[i]]++;
                }
                i++;
            }
        }
        return ans.second;
        
    }
};
