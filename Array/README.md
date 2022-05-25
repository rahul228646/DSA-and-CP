# Notes

## Import Algorithms

### Kadne 
   To find continuous subarray with max sum
      
      int Kadne(vector<int>& nums) {
              int n = nums.size(), k = 0, cnt = 0; 
              int mx_so_far = 0, mx = INT_MIN;
              for(int i = 0; i<n; i++) {
                  mx_so_far += nums[i];
                  mx = max(mx, mx_so_far);
                  if(mx_so_far<0) mx_so_far = 0;
              }
        return mx;  
      }
