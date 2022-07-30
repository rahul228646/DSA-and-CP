https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!

Sliding Window (Shrinkable) : 

    int i = 0, j = 0, ans = 0;
    for (; j < N; ++j) {
        // CODE: use A[j] to update state which might make the window invalid
        for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
            // CODE: update state using A[i]
        }
        ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
    }
    return ans;


Sliding Window (Non-shrinkable) :

      int i = 0, j = 0;
      for (; j < N; ++j) {
          // CODE: use A[j] to update state which might make the window invalid
          if (invalid()) { // Increment the left edge ONLY when the window is invalid. In this way, 
          the window GROWs when it's valid, and SHIFTs when it's           
          invalid
              // CODE: update state using A[i]
              ++i;
          }
          // after `++j` in the for loop, this window `[i, j)` of length `j - i` MIGHT be valid.
      }
      return j - i; // There must be a maximum window of size `j - i`.
