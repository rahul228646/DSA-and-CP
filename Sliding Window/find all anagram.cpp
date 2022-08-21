// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(auto i : p) mp[i]++;
        int i = 0, j = 0, n = s.length(), count = mp.size(), m = p.size();
        vector<int> ans;
        for(;j<n;j++) {
            if(mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            while(count == 0) {
                if(j-i+1 == m) {
                    ans.push_back(i);
                }
                if(mp.count(s[i])) {
                    if(mp[s[i]] == 0) count++;
                    mp[s[i]]++;
                }
                i++;
            }
        }
        return ans;
        
    }
};
