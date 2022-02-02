// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = 0, k = p.length(), count = 0;
        unordered_map<char, int> m;
        for (auto l : p) {
            m[l]++;
        }
        count = m.size();
        vector<int> ans;
        while(j<s.length()) {
            if(m.count(s[j])) {
                m[s[j]]--;
                if(m[s[j]] == 0) {
                    cout<<s[j];
                    count--;
                }
            }
            if(j-i+1 < k)
                j++;
            
            else if (j-i+1 == k) {
                // cout<<i<<" "<<j<<" "<<count<<endl;
                if(count == 0) {
                    ans.push_back(i);
                }
                if(m.count(s[i])) {
                    if(m[s[i]] == 0)
                        count++;
                    m[s[i]]++;
                }
                j++;
                i++;
            }

        }
        return ans;
    }
};
