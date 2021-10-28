

	void pushZerosToEnd(int arr[], int n) {
	    int count = 0, j = 0;
	   for(int i = 0; i<n; i++) {
	       if(arr[i] == 0) {
	           count++;
	           continue;
	       }
	       arr[j++] = arr[i];
	   }
	   while(j<n) {
	       arr[j++] = 0;
	   }
	}
