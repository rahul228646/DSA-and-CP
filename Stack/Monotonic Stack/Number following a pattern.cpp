https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/

  string printMinNumberForPattern(string s){
        // code here 
        string ans;
        char c = '1';
        stack<char> st;
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            if(s[i] == 'D') {
                st.push(c);
                c = c+1;
            }
            else{
                st.push(c);
                c = c+1;
                while(st.size()) {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        st.push(c);
        c = c+1;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
  }
