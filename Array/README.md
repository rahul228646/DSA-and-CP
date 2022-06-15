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
      
## STL

   Set and Unordered Set
   
   set operations - O(log n)  &  unordered_set operations - O(1) 
   
      insert()
      count()
      begin()  :  Return an iterator pointing to the first element
      end()    :  Return an iterator pointing to the element element
      find()
      clear()  :  empty the set
      erase()  :  removes a particular element
   
   
