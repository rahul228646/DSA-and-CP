
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n) {
            if(n&1) count++;
            n = n>>1;
        }
        return count;
    }

// or 

// Brian Kernighan’s Algorithm: 
    int setBits(int n) {
        // Write Your Code here
         int count = 0;
        while(n>0){
			//AND n and n-1 as long as n != 0, and increment count subsequently.
            n = n&(n-1);
            count++;
        }
        return count;
    }


