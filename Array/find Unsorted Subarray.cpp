// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
// Time : O(N) Space : O(N)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), first = nums.size(), last = 0;
        s.push(0);
        for(int i = 1; i<n; i++) {
            if(nums[i] >= nums[s.top()]) s.push(i);
            else {
                while(!s.empty() && nums[s.top()] > nums[i]) {
                    first = min(first, s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
        s = stack<int>();
        s.push(n-1);
        for(int i = n-2; i>=0; i--) {
            if(nums[i] <= nums[s.top()]) s.push(i);
            else {
                while(!s.empty() && nums[s.top()] < nums[i]) {
                    last = max(last, s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
     
        return last - first > 0 ?  last - first + 1 : 0;
    }
};
