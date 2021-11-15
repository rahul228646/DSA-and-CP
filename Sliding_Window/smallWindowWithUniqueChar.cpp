// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// Time : O(n) Space : O(n) or O(256)

    string findSubString(string str)
    {
        unordered_map<char, int> m;
        for (auto i : str) m[i]++;
        int count = 0, n = str.length(), j = 0, i = 0, mx = INT_MAX;
        string ans;
        count = m.size();
        
        m.clear();
        while(j<n) {
            if(m.size() < count) {
                m[str[j]]++;
                
            }
            while(m.size() == count) {
                // cout<<str.substr(i, j-i+1)<<endl;
                if(mx > j-i+1) {
                    mx = j-i+1;
                    ans = str.substr(i, j-i+1);
                }
                m[str[i]]--;
                // cout<<m[str[i]]<<endl;
                if(m[str[i]] == 0) m.erase(str[i]);
                
                i++;
                
            }
            j++;
        }
        return ans;
    }
