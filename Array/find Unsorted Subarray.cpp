// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/

// Time : O(N) Space : O(1)

// 1. find the min number from left side if it is not sorted
// 2. find the max number from right side if it is not sorted
// 3. from left side find the first no. which is greater than mn
// 4. from right side find the first no. which is smaller than mx

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        int n = nums.size(), left, right, mn = INT_MAX, mx = INT_MIN;
        bool flag = false;
        for(int i = 1; i<n; i++) {
           if(nums[i] < nums[i-1]) flag = true;
           if(flag) mn = min(mn, nums[i]); 
        }
        flag = false;
        for(int i = n-2; i>=0; i--) {
           if(nums[i] > nums[i+1]) flag = true;
           if(flag) mx = max(mx, nums[i]); 
        }
        
        for(left = 0; left <n; left++) {
            if(mn < nums[left]) break;
        }
        
        for(right = n-1; right>=0; right--) {
           if(mx > nums[right]) break;

        }
        cout<<mn<<" "<<mx<<endl;
        cout<<left<<" "<<right<<endl;
        return right - left > 0 ?  right - left + 1 : 0;
    }
};

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
