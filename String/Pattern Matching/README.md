# Pattern Matching

## KMP
    https://www.youtube.com/watch?v=BXCEFAzhxGY
    https://www.scaler.com/topics/data-structures/kmp-algorithm/

    To avoid partial matches 

    String : c c c c c c c d
    Pattern : c c c d

    we create an Lps array to skip computation the partial matches
    Lps array represents longest prefix that is also a suffix
    eg - for a b a b d a b d
    lps -    0 0 1 2 0 1 2 3

    If there is a match, increment both i and j.
    If there is a mismatch after a match, place j at LPS[pattern[j - 1]] and compare again.
    If j = 0, and there is a mismatch, increment i. 

    a d s g w a d s x d s g w a d s g z
      ------------- |
    d s g w a d s g z      (x != g)
    ------------- |
    
    instead of going back in i and j we start searching from g (2nd index) because ds is a suffix that is also a prefix

    a d s g w a d s x d s g w a d s g z
                ---
    d s g w a d s g z  [0 0 0 0 0 1 2 3 0] --> (lps)
    ---       ---

    a d s g w a d s x d s g w a d s g z
                --- |
    d s g w a d s g z  [0 0 0 0 0 1 2 3 0] --> (lps)
    --- |      
    
    
## Rabin Carp

    1. Calculate Hash of Pattern String -- O(N)
    
        abc
        p = prime no. greater than the range of characters i.e. 
        for small letters 1-26 take p {29, 31, ....} 
        for both letters 1-52 take p {29, 31, ....} 

        (a-'a'+1)*(p)^0  + (b-'a'+1)*(p)^1 + (c-'a'+1)*(p)^2

    2. Generate Prefix Hash Array of the given text string O(N)
    
    3. use silding window on text string to Compute the hash for the given string and compare it with the hash of pattern
    
        for text string
        
        0 1 2 3 4 5 6
        d s a b c x y
            -----
        hash of abc = (prefixHash[4] - prefixHash[1]) / p^2
        which should be equal to the hash of pattern
        or
        (prefixHash[4] - prefixHash[1]) == (hash of pattern)*p^2
