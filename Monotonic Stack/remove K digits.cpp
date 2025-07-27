// https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation
// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n<=k) return "0";
        string ans = "";
        stack<char> st;
        st.push(num[0]);
  
        for(int i = 1; i<n; i++) {
             while(!st.empty() && st.top() > num[i] && k) {
                st.pop();
                k--;
             }
             if(st.empty() && num[i] == '0'){
                continue;
             }
             else {
                  
                 st.push(num[i]);
             }
        }
        while(!st.empty() && k--) {
            st.pop();
        }

        while(!st.empty()) {
            ans = st.top() + ans; 
            st.pop();
        }
        if(!ans.length()) return "0";
        return ans;
    }
};


