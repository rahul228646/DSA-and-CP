// https://leetcode.com/problems/smallest-string-with-swaps/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int v) {
        if(parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }
    void union_op(int to, int from) {
        from = find(from);
	    to = find(to);
        if (from == to) return ;
        if(rank[from] > rank[to]) {
            parent[to] = from;
            
        }
        else if(rank[from] < rank[to]) {
            parent[from] = to;
        }
        else {

            parent[from] = to;
            rank[to] += 1;
        }
       
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 0);
        // form union of connected components
        for(auto i : pairs) {
            union_op(i[0], i[1]);
        }
        // put all child of a node in a an arraya
        unordered_map<int, vector<int>> child;
        for (int i = 0; i < n; i++){
            child[find(i)].push_back(i);
        }
//       all characters with in a group can be arranged in any number of ways
       for (auto &p : child) {
           string temp = "";
            for (int i : p.second) temp += s[i];
            sort(temp.begin(), temp.end());
            int k = 0;
            for (int i : p.second)
                s[i] = temp[k++];
        }
        return s;
    }
};

// 0-2-3
//   | 
//   1  
   
