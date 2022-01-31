
Time : O(n^2) Space : O(n)

		{1, 11, 2, 10, 4, 5, 2, 1}
	
   	 1   2   2   3  3  4  2  1 -- lis
		 1   5   2   4  3  3  2  1 -- lds
		 1   6   3   6  5  6  3  1 -- lis+lds-1
       
int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    
	    vector<int> lis(arr.size(), 1);
	    vector<int> lds(arr.size(), 1);
	     int n = arr.size();
	    

    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                mx = max(mx, lis[j]);
        }
        lis[i] = mx + 1;
    }
     for (int i = n-1; i >=0; i--) {
        int mx = 0;
        for (int j = n-1; j > i; j--) {
            if (arr[i] > arr[j])
                mx = max(mx, lds[j]);
        }
        lds[i] = mx + 1;
    }
	    
	    
	 
	    int max = lis[0] + lds[0]-1; // to one elemnt will include in both lis and lds , there -1 is to nullify double addition 
        for (int i = 1; i < n; i++) {
            // cout<<lis[i]<<" "<<lds[i]<<endl;
            if (lis[i] + lds[i] - 1 > max)
                max = lis[i] + lds[i]-1;
        }
        return max;
	    
	    
	}
  
  
  
