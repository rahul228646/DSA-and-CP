

kadane - Algorith to find maximum contiguous subarray sum
  
    int kadane(int arr[]) {
        int maxEndingHere = 0;
        int maxSoFar = 0;
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
