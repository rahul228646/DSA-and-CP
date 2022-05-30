https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
class Solution {
public:
    
    vector<int> finalPrices(vector<int>& p) {
        stack<pair<int, int>> st; // monotonic increasing stack;
        st.push({p[0], 0});
        for(int i = 1; i<p.size(); i++) {
            while(st.size() && st.top().first>=p[i]) {
                p[st.top().second] = st.top().first - p[i]; 
                st.pop();
            }
            st.push({p[i], i});
        }

        return p;
    }
};

