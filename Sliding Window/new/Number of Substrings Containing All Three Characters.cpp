https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> f;
        int l=0, r=0, cnt=0;
        int n = s.size();
        while(r < n) {
            f[s[r]]++;
            while(f['a'] && f['b'] && f['c']) {
                cnt += n-r;
                f[s[l++]]--;
            }
            r++;
        }
        return cnt;
    }
};

a b c a b c
l   r

abc, abca, abcab, abcabc = ( n(6) - r(2) ) = 4
a b c a b c
  l   r   
bca, bcab, bcabc = ( n(6) - r(3) ) = 3   

a b c a b c
    l   r   
cab, cabc = ( n(6) - r(4) ) = 2    

a b c a b c
      l   r   
abc = ( n(6) - r(5) ) = 1  

4 + 3 + 2 + 1 = 10   
