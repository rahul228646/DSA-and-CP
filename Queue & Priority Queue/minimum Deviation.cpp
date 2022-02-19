// https://leetcode.com/problems/minimize-deviation-in-array/submissions/
// Time : O(n(logn)^2) 
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        priority_queue<int> pq;
        for(auto &i : nums) {
            if(i%2 != 0) i *= 2;
            mn = min(mn, i);
            // cout<<i<<endl;
            pq.push(i);
        } 
        int dev = INT_MAX;
        while(pq.top() % 2 == 0) {
            int curr = pq.top();
            pq.pop();
            dev = min(dev, curr-mn);
            curr /= 2;
            mn = min(mn, curr);
            pq.push(curr);
        }
        dev = min(dev, pq.top()-mn);
        return dev;
    }
};

    
    
