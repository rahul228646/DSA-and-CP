
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
        int count=0;
        while(n) {
           int rsbm = n & (-n);
           n = n - rsbm;
           count++;
        }
        return count;
    }
