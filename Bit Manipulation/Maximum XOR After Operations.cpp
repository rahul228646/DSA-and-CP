

class Solution {
public:
    int maximumXOR(vector<int>& nums) {

        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            a|=nums[i];
        }
        
        return a;

    }
};


// WHY A SIMPLE OR IS WORKING.

// Must Know:

// We can Toggle 1->0 using a AND but Can't toggle 0->1. 0&0=0 0&1=0 but 1&0=1.

// 1001
// 0110
// for this two number the possible max number(According to problem) is when in every position we get 1.(IE, 1111).

// 1101
// 1111
// 1111
// 1001
// in order to get xor result as 1 in any position we need to have odd number of 1. why?-> 1^1=0 but 1^1^1=1=>0^1=1;

// PS:Now the problem become easy....What we need to is we need to check if in every bit position we can get 1 or not?
// if any bit position we have 1 or more one(no matter even times or odd using the nums[i] AND (nums[i] XOR x) operation we can make it 1 at that bit position.
// and if there is no 1 in any number of that specific bit position. we can make that 1.

// so what is have to do is. where is we can make 1 in bit position just make that 1.

// Here OR come into picture or just sim. check in a specifict bit-position is there any 1 is present in any number then going to make that position 1.
// if there is no 1... can't do any thing.
// Example:
// 2: 010
// 3: 011
// 1: 001
// as a result of the all elements or we are oging to get (011)=3 and thats should be the maximum ans for this question.
// as we dont have any o is 2nd bit it trun out to impossible to make that bit 1 in max ans.
// but as we have 1s in 1st and 0th bit we can manipulate the number of 1s using nums[i] AND (nums[i] XOR x) and thats why just making or them give us 1 in ans.

// ==> nums[i] AND (nums[i] XOR x)
// nums[i] AND Y
// lets 10 AND Y
// the best things we can do according to the need of our problem is => 00 (toogle the 1 to 0 (when Y=00 ) but never able to make 11
