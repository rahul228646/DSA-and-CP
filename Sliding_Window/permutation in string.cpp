https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string p, string s) {
         int i = 0, j = 0, k = p.length(), count = 0;
        unordered_map<char, int> m;
        for (auto l : p) {
            m[l]++;
        }
        count = m.size();
        while(j<s.length()) {
            if(m.count(s[j])) {
                cout<<i<<" "<<j<<endl;
                m[s[j]]--;
                if(m[s[j]] == 0) {
                    count--;
                }
            }
            if(j-i+1 < k)
                j++;
            
            else if (j-i+1 == k) {
                if(count == 0) {
                    return true;
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
        return false;
    }
};
