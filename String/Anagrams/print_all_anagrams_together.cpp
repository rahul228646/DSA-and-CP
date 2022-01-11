
// time : O(N * M * logM) space : O(M * N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(auto i : str) {
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        for(auto i : mp) ans.push_back(i.second);
        return ans;
    }
};

// time : O(N * M) space : O(M * N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        map<map<char, int>, vector<string>> mp;
        for(auto s : str) {
            map<char, int> temp;
            for(auto c : s) {
                temp[c]++;
            }
            mp[temp].push_back(s);
        }
        for(auto i : mp) ans.push_back(i.second);
        return ans;
    }
};
