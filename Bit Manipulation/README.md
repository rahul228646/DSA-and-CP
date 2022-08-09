- representation of binary - 

  - msb is 0 = covert to decimal
  - msb is 1 = 2's compliment -> convert to decimal -> add -ve sign
  
- min number for 4 bits is -8 (1000)
- max number for 4 bits is  7 (0111)
- range for n bits is (-2^n to 2^n - 1)
<!-- - if a number in binary is 1001 then 1001 >> 2 will give 1110 -- two one are added since msb is one
- if a number in binary is 0111 then 0111 >> 2 will give 0001 -- two zeros are added since msb is zero
- ">>>x" will add 0 from front irrespective of the MSB -->
- | to switch on a bit, & to turn off a bit , ^ to toggle a bit and & to check a bit

<img width="474" alt="Screenshot 2022-03-30 at 4 15 35 PM" src="https://user-images.githubusercontent.com/56363090/160814256-51724c98-e2b1-47cb-948b-c6f058fa0a69.png">

- right most set bit mask = x & (-x) where -x is 2's compliment of x or x & (~x + 1) where (~x + 1) is 2's compliment of x

## Brian Kernighan's Algorithm 
    It states that for an integer N :- (N) AND (N-1) is equivalent to 
    N but with all the bits from and including the rightmost set bit (1) flipped.

    Example :-

    N = 7 ==>B==I==N==A==R==Y==> 111
    N = 6 ==>B==I==N==A==R==Y==> 110
    N = 5 ==>B==I==N==A==R==Y==> 101
    N = 4 ==>B==I==N==A==R==Y==> 100
    N = 3 ==>B==I==N==A==R==Y==> 011
    N = 2 ==>B==I==N==A==R==Y==> 010
    N = 1 ==>B==I==N==A==R==Y==> 001

    In above, the rightmost set bit is bold. Under each rightmost set bit (boldened),
    the bits to it's right and including it are flipped (shown in italics).

    Let's say the number whose set bits we wish to count is 7.

    7 AND 6 ===> 110
    6 AND 5 ===> 100
    5 AND 4 ===> 100
    4 AND 3 ===> 000

    From above, we can see that we got a non-zero number upon ANDing 3 times which corresponds to the 3 set bits in 7.

    So, we can simple run the loop for each number whose count of set bits is to be found and apply the algorithm.
    
    int setBits() {
     int count = 0;
        while(n>0){
            n = n&(n-1);
            count++;
        }
     return count;
    }

