

bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if(str1.length() != str2.length()) return false;
        int count = 0, freq[26]={0}; // constant space
        for(auto i:str1) freq[i-'a']++;
        for(auto i:str2) if(freq[i-'a']>0) freq[i-'a']--; else count++;
        return (count<=k);
    }
