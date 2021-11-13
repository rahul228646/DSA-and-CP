// https://leetcode.com/problems/daily-temperatures/submissions/

// time : O(n) - there will never be a case where we will have to pop all n elements space : log(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector <int> ans(n, 0); 
        stack <int> st;
        for(int i = n-1; i>=0; i--) {
           
            if(st.empty()) {
                ans[i] = 0;
                st.push(i);
            }
            
            while(!st.empty() && t[i] >= t[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
