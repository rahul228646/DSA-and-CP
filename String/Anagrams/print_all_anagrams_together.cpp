
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
