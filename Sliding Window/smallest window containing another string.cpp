

// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string p) {
         unordered_map<char, int> mp;
        for(auto i : p) mp[i]++;
        int i = 0, j = 0;
        int n = s.length();
        pair<int, string> ans = {INT_MAX, ""};
        int count = mp.size();
        while(j<=n) {
            if(j<n && mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    count--;
                }
                
            }
            while(count == 0 && i<=j) {
                if(ans.first > j-i+1) {
                    // cout<<j<<endl;
                    ans.first = j-i+1;
                    ans.second = s.substr(i, j-i+1);
                }
                if(mp.count(s[i])) {
                    if(mp[s[i]] == 0) count++;
                    mp[s[i]]++;
                }
                i++;
            }
            j++;
        }

        return ans.second;
    }
};
