https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string p, string s) {
         int i = 0, j = 0, k = p.length(), count = 0, n = s.size();;
        unordered_map<char, int> mp;
        for (auto l : p) {
            mp[l]++;
        }
        count = mp.size();
        for(;j<n;j++) {
            if(mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            while(count == 0) {
                if(j-i+1 == k) return true;
                if(mp.count(s[i])) {
                    if(mp[s[i]] == 0) count++;
                    mp[s[i]]++;
                }
                i++;
            } 
        }
        return false;
    }
};
