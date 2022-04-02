https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
bool isPalindrome(string s) {
    int index = 0;
    for(int i = 0; i<s.length(); i++) {
        if(isalnum(s[i]))
            s[index++] = tolower(s[i]);
    }
    s = s.substr(0, index);
    cout<<s<<endl;
    index = 0;
    int end = s.length()-1;
    while(index<end) {
        if(s[index] != s[end])
            return false;
        index++;
        end--;
    }
    return true;
}
};
