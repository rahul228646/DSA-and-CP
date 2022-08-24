
// arr is sorted
    long long findSmallest(long long arr[], int n) {
        // code here
        long long res = 1;
        for(int i = 0; i<n; i++) {
            if(res < arr[i]) {
                return res;
            }
            res += arr[i];
        }
        return res;
    }

- {1, 2, 3, 9, 10, 20, 28}
  smallest ans can be 1, now traverse the array
  1           - now smallest no can be 1 + 1 = 2
  1 2         - , ,   2+2 = 4
  1 2 3       - , ,   4+3 = 7
  1 2 3 9     - since 7 is less than 9, using this subset we cannot represent 7 , this is the answer. 
  
