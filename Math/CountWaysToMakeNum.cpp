

// N = a + (a+1) + (a+2) + .. + (a+L) 
// => N = (L+1)*a + (L*(L+1))/2 
// => a = (N- L*(L+1)/2)/(L+1) 
// We substitute the values of L starting from 1 till L*(L+1)/2 < N 
// If we get ‘a’ as a natural number then the solution should be counted.


long int countConsecutive(long int N)
{
    long int count = 0;
    for (long int L = 1; L * (L + 1) < 2 * N; L++) {
        double a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
        if (a - (int)a == 0.0)
            count++;
    }
    return count;
}
