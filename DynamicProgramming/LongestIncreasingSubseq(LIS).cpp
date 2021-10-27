

https://www.youtube.com/watch?v=odrfUCS9sQk

// time : o(n^2) 
// space : o(n)
// dp is storing longest increasig subseq len that is ending at i

    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp (n, 0);
       int overallMax = 0;
       for(int i = 0; i<n; i++) {
           int max = 0
           for(int j = 0; j<i ; j++) {
               if(a[j] > a[i]) {
                 if(dp[j] > max)
                   max = dp[j];
               }
           }
           dp[i] = max+1;
           overallMax = max(dp[i], overallMax);
       }
       
    
       return overallMax;
    }

https://www.youtube.com/watch?v=TocJOW6vx_I
// time : o(nlogn) 
// space : o(n)
// process : in this program we are trying to store the lowest sequence 
// consider 2 5 3 4 --> first we inset 2 then we check if 5 is gretar than last element of the sequence or not, if yes we push it int the series.
// seq : 2 5, now we compare last element of the sequence i.e 5 with 3 and since 3 is smaller we find the number which is just greater than than 3 and replace it with 3
// seq : 2 3

    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> seq;
       seq.push_back(a[0]);
       for(int i = 1; i<n; i++) {
           if(seq.back()<a[i]) {
               seq.push_back(a[i]);
           }
           else {
               int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
               seq[idx] = a[i];
           }
           
       }
       return seq.size();
    }
