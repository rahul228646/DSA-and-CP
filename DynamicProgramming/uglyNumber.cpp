
// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15,
// shows the first 11 ugly numbers. By convention, 1 is included.
// https://www.youtube.com/watch?v=Lj68VJ1wu84
// Time : O(n) 
// Space: O(n)
  
	ull getNthUglyNo(int n) {
	    // code here
	    vector<ull> dp (n+1, 0);
	    dp[1] = 1;
	    ull nxt_mul_2_pointer = 1, nxt_mul_3_pointer = 1 , nxt_mul_5_pointer = 1;
	    ull nxt_no_2 = 2, nxt_no_3 = 3, nxt_no_5 = 5;
	    for(int i = 2; i<=n; i++) {
	        dp[i] = min(nxt_no_2, min(nxt_no_3, nxt_no_5));
	        if(dp[i] == nxt_no_2) {
	            nxt_mul_2_pointer++;
	            nxt_no_2 = 2*dp[nxt_mul_2_pointer];
	        }
	        if(dp[i] == nxt_no_3) {
	            nxt_mul_3_pointer++;
	            nxt_no_3 = 3*dp[nxt_mul_3_pointer];
	        }
	        if(dp[i] == nxt_no_5) {
	            nxt_mul_5_pointer++;
	            nxt_no_5 = 5*dp[nxt_mul_5_pointer];
	        }
	    }
	    return dp[n];
	}
