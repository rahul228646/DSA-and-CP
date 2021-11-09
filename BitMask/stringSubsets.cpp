
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/solution/
consider a string abdf

create a bitmask
    int bitmask(const string& word) {
        // Build a bitmask of chars to represent each word
        // the builtin std::bitset also works
        int mask = 0;
        for (char letter : word) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }

mask = 1+2+8+32 = 43
  
to create subset use the code below

    for (subset = bitmask; subsets >= 0; subset = (subset - 1) & bitmask) {
      // do what you want with the current subset...
    }

subset = (subset - 1) & bitmask

101011 - 32 8 2 1   {f d b a}
101010 - 32 8 2     {f d b}
101001 - 32 8 1     {f d a}
101000 - 32 8       {f d}
100011 - 32 2 1     {f b a}
100010 - 32 2       {f b}
100001 - 32 1       {f a}
100000 - 32         {f}
001011 - 8 2 1      {d b a}
001010 - 8 2        {d b}
001001 - 8 2 1      {d a}
001000 - 8          {d}
000011 - 2 1        {b a}
000010 - 2          {b}
000001 - 1          {a}

