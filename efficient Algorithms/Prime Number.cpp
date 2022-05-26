// Sieve Of Eratosthenes - given all the prime no less than a given number

Time Complexity: O(n*log(log(n)))

Auxiliary Space: O(n)
  
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}


Now let’s assume our current prime number is 2. In the first iteration, we’ll mark N/2 elements. 
Like this, when our current prime number is 3, we assign mark N/3 numbers. 
The total number times we runs the loop would be equal to:
--> N/2 + N/3 + N/5 + N/7 ......
--> N * ( 1/2 + 1/3 + 1/5 + 1/7 ...)
--> ( 1/2 + 1/3 + 1/5 + 1/7 ...) ==> log (log N)
--> N * log (log N)  

