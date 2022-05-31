// https://www.youtube.com/watch?v=vcv3REtIvEo
// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> mystack;
        for(int i=0;i<n;++i)    //Fill left
        {
            if(mystack.empty())
            {    left[i] = 0;   mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                left[i] = mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        while(!mystack.empty()) //Clear stack
            mystack.pop();
        for(int i=n-1;i>=0;--i) //Fill right
        {
            if(mystack.empty())
            {   right[i] = n-1; mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                right[i] = mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        int mx_area = 0;    //Stores max_area
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
        return mx_area;
    }
};

// or

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n = h.size();
        stack<int> st; // increasing stack
        vector<int> ans(n, 0);
        st.push(0);
        for(int i = 1; i<n; i++) {
            
            while(st.size() && h[st.top()] > h[i]) {
                ans[st.top()] += (i - st.top())*h[st.top()];
                st.pop();
            }
            if(st.size()) {
                if(h[st.top()] == h[i])
                    ans[i] += (i-st.top()) * h[i]; 
                else 
                    ans[i] += (i-(st.top()+1)) * h[i]; 
            }
            else {
                ans[i] += (i-0)*h[i];
            }
            st.push(i);
            
        }
        int res = 0;
        while(st.size()) {
            ans[st.top()] += (n - st.top())*h[st.top()];
            st.pop();
        }
        
        
        for(auto i : ans) {
            // cout<<i<<endl;
            res = max(res, i);
        }
        return res;
    }
};




