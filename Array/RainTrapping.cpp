
https://leetcode.com/problems/trapping-rain-water/submissions/
https://www.youtube.com/watch?v=C8UjlJZsHBw

// time : O(N) space : O(N)

 int trap(vector<int>& h) {
        int n = h.size(), mx = 0;
        vector<int> l(n, 0), r(n, 0);
        for(int i = 0; i<n; i++) {
            mx = max(h[i], mx);
            l[i] = max(l[i], mx);
        }
        mx = 0;
        for(int i = n-1; i>=0; i--) {
            mx = max(h[i], mx);
            r[i] = max(r[i], mx);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += min(l[i], r[i])-h[i];
        }
        return ans;
    }


// ------------------------

// time : O(N) space : O(N)
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        int LMax = height[0], RMax = height[n-1];
        
        vector<int> maxLeft(n, 0), maxRight(n, 0);
        // max element to the left
        for(int i = 1; i<n; i++) {
            maxLeft[i] = LMax;
            LMax = max(height[i], LMax);
        }
        // max element to the right
        for(int i = n-2; i>=0; i--) {
            maxRight[i] = RMax;
            RMax = max(height[i], RMax);
        }
        // water inside a block is min(maxLeft, maxRight) - element 
        for(int i = 1; i<n-1; i++) {
            if(height[i]<maxLeft[i] && height[i]<maxRight[i])
                result += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return result;
    }

// time : O(N) space : O(1)
    int trap(vector<int>& height) {
        int left = height[0];
        int right = height[height.size()-1];
        int start = 1, end = height.size()-1;
        int ans = 0;
        while (start<=end) {
            if(left <= right) {
                if(height[start] > left) {
                    left = height[start];
                }
                else {
                    ans += left - height[start]; 
                }
                start++;
            }
            else {
                if(height[end] > right) {
                    right = height[end];
                }
                else {
                    ans += right - height[end]; 
                }
                end--;
            }
        }
        return ans;
    }
