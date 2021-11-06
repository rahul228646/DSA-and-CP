
// Time Complexity: O(2 * N) = O(N) --> Each number in the input array is visited twice.

// Space Complexity: O(1) --> Uses constant auxiliary space.
  
class Solution {
    public int[] singleNumber(int[] nums) {
        if (nums == null || nums.length < 2 || nums.length % 2 != 0) {
            throw new IllegalArgumentException("Invalid Input");
        }

        int aXORb = 0;
        for (int n : nums) {
            aXORb ^= n;
        }

        int rightSetBit = aXORb & -aXORb; // -a is 2's complement of a
        int a = 0;
        for (int n : nums) {
            if ((n & rightSetBit) != 0) {
                a ^= n;
            }
        }

        return new int[] {a, aXORb ^ a};
    }
}

// The idea is to use XOR to remove all numbers that appear exactly twice. Thus, in the first pass, we will XOR all nums in the input array. We will be left with XOR (aXORb) of two numbers that appear exactly once. (Let's call these numbers A and B.)

// In XOR, a bit is set in the result if both bits at the same locations are different.
// Now find the rightmost set bit in aXORb. This will give us the rightmost bit that is different in A & B.

// We can now go through all numbers in input array again (second pass) and XOR the numbers that have this bit set to 1. This will give us the first number A.
// To get the second number perform aXORb ^ A.

// Example

// Let us use this input: nums = [1,2,1,3,2,5]
// Since we will need the binary representation of each of these numbers, I have converted them here for simplicity [0x001, 0x010, 0x001, 0x011, 0x010, 0x101]

// Now perform XOR each of these numbers:
// aXORb = 1 ^ 2 ^ 1 ^ 3 ^ 2 ^ 5 = 0x110

// In this aXORb rightmost set bit can be found by aXORb & -aXORb which will give us:
// rightSetBit = 0x010;

// In the second pass, we try to XOR all numbers that have this bit set to 1. There are total three such numbers: [2, 2, 3]. XOR of these numbers should give us 3. This can be assigned to A. To get B we can perform XOR of A and aXORb. In this example, aXORb ^ A = 0x110 ^ 0x011 = 0x101 (which is 5 in decimal).

// Thus the output result is [3,5].

