class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
        stack<int> st;
        for(int i = 0; i<n; i++) st.push(i);
        while(st.size()!= 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b] == 1) {
                st.push(b);
            }
            else {
                st.push(a);
            }
        }
        int ans = st.top();
        for(int i = 0; i<n; i++) {
            if(i!=ans && (M[ans][i] || !M[i][ans])) {
                return -1;
            } 
            
        }
        return ans;
        
    }
};
