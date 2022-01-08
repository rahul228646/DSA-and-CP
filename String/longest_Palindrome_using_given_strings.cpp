
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
  

class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string, int> m;
        int cnt = 0;
        bool flag = true;
        for(auto i : w) {
            m[i]++;
        } 
        for(auto i : m) {
            // cout<<i.first<<" "<<i.second<<endl;
            string s = i.first;
            reverse(s.begin(), s.end());
            if(m.find(s) != m.end()) {
                int temp = min(m[s], i.second);
                if(i.first[0] == i.first[1]) {
                    temp -= temp%2;
                }
                cnt += (temp);
            }
            if(i.first[0] == i.first[1] && (i.second % 2 != 0) && flag) {
                cnt++;
                flag = false;
            }
        }
        return cnt*2;
    }
};
