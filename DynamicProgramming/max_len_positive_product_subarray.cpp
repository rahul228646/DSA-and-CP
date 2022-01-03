
https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

class Solution {
public:
     int getMaxLen(vector<int> nums) 
    { 
        int framestart = -1, firstneg = -2, len = 0, neg = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 0) // reset everytime if zero
            {  
                neg = 0;framestart = i;firstneg = -2;
            } 
            else 
            {
                if (nums[i] < 0) neg++;  // number of negatives in  current frame means (frame excluding zero)
                if (neg == 1 && firstneg == -2) firstneg = i;   // init firstneg cnt neg;
                if (neg % 2 == 0) len = max(len, i - framestart);  //if curr cnt neg is framestart;
                else len = max(len, i - firstneg);  // first firstneg after last zero;
            }
        }
        return len;

    }
};

            [1, -2,  0,  2,  0,  2, -1, 2, -2, 3, -4, 5, 8]
neg          0   1   0   0   0   0   1  1   2  2   3  3  3
i            0   1   2   3   4   5   6  7   8  9  10  11 12                                     
firstNeg    -2   1  -2  -2  -2  -2   6  6   6  6   6  6  6                           
framestart  -1  -1   2   2   4   4   4  4   4  4   4  4  4                                       
len          1   1   1   1   1   1   1  1   4  5   5  5  6            
  
  pointer to first negative can be used to count even -ve number ie. if(neg % 2 == 0) we will consider whole array , starting from the lst zero encountered
  if (neg % 2 != 0) we will count the len from the first encountered -ve number (excluding it) this will make the product -ve; 
