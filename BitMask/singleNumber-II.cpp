

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,c=0,ans=0;
        for(int i=0;i<32;i++){// check for the ith bit
            c=0;
            for(int j:nums){
                if(j&(1<<i)) c++; // if ith bit is set increment the cnt
            }
            if(c%3) ans+=(1<<i); // if cnt is not divisible by 3 means ith bits is set update the answer
        }
        return ans;
    }
};

// Let's take an example:

// 3 1 1 1 2 2 2

// From the above example it is clear that 3 is the answer. Now, let us look at the binary representation of the numbers.

// 3 ----> 0 0 1 1
// 1 ----> 0 0 0 1
// 1 ----> 0 0 0 1
// 1 ----> 0 0 0 1
// 2 ----> 0 0 1 0
// 2 ----> 0 0 1 0
// 2 ----> 0 0 1 0

// If you notice in the above table, numbers of ones in some columns are in the form 3n and 3n+1, where n is the frequency of the numbers.
// Whichever columns have 3n+1 1's must contain the element that occurs only once and thats what we want as the result.
// So, we check for every bit in the whole array and if the count of that bit is in the form 3n+1 then we add it to our result.
