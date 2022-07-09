https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long int> prev_less_element_dist(n, 0);
        vector<long long int> next_less_element_dist(n, 0);
        stack<int> st;
        for(int i = 0; i<n; i++) {
            while(st.size() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(!st.size()) prev_less_element_dist[i] = i+1;
            else prev_less_element_dist[i] = i-st.top();
            st.push(i);
            
        }
        st = stack<int>();
        for(int i = n-1; i>=0; i--) {
            while(st.size() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.size()) next_less_element_dist[i] = n-i;
            else next_less_element_dist[i] = st.top()-i;
            st.push(i);
            
        }
        const int mod = 1e9+7;
        long long int ans = 0;
        
        for(int i = 0; i<n; i++) {
            ans += 1LL*( (arr[i]%mod) * ( (prev_less_element_dist[i]%mod)  * (next_less_element_dist[i]%mod) )) %mod ;
            // cout<<prev_less_element_dist[i]<<" "<<next_less_element_dist[i]<<endl;
        }
        
        return ans%(mod);
    }
};
// 3 2

// 44 + 81*2 + 94 + 43*3 + 5*3


    
