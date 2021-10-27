
https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

    int kadane(int arr[], int n) {
        int maxEndingHere = 0;
        int maxSoFar = INT_MIN;
        for(int i = 0; i<n; i++) {
            maxEndingHere = maxEndingHere + arr[i];
            if(maxSoFar < maxEndingHere) {
                maxSoFar = maxEndingHere;
            }
            if(maxEndingHere < 0) {
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    } 
    int circularSubarraySum(int arr[], int n){
        
      // kadane's algorith for maximum contiguos subarray sum
        int sumNoWrap = kadane(arr, n);
      // if all elements are negative kadane will give the smallest negative number, that will be the ans
        if(sumNoWrap < 0) return sumNoWrap;
      // for wrap consider {10, -12, 11} 
      // answer should ne 10+11 = 21 
      // we chnage sign & apply kadane {-10, 12, -11} --> 12
      // we add this to the original sum (10-12+11) = 9 --> 21
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            arr[i] = arr[i]*-1;
        }
        int sumWrap = kadane(arr, n) + sum;
        
        return max(sumWrap, sumNoWrap);
    }
