
// variation lis

	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> lis(n, 0);
      int overallMax = 0;
      for(int i = 0; i<n; i++) {
          int maximumForEach = 0;
        for(int j = 0; j<i; j++) {
            if(arr[j]<arr[i]) {
                maximumForEach = max(lis[j], maximumForEach);
            }
        }
        // lis[i] = maximumForEach + 1 (original)
        lis[i] = maximumForEach + arr[i];
        overallMax = max(overallMax, lis[i]);
      }
      return overallMax;
	  }  
};
