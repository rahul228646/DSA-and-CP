// https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    int checkPalindrome(string s, int i, int j) {
  
        while(j>i) {
           if(s[i] == s[j]) {
               i++;
               j--;
           }else {
               return false;
           }
        }
        return true;
    }
    bool validPalindrome(string s) {
       int i = 0, j = s.length()-1, count1 = 0, count2 = 0;
       while(j>i) {
           if(s[i] != s[j]) {
               return checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j);
           }
           i++;
           j--;
       }
      
       
        return true;
    }
};

