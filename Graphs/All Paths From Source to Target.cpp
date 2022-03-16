https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start = 0, end = graph.size()-1;
        queue<pair<int, vector<int>>> q;
        vector<vector<int>> ans;
        q.push({start, {start}});

        while(!q.empty()) {
            auto [node, path] = q.front();
            q.pop();
            if(node == end) {
                ans.push_back(path);
            }
            for(auto i : graph[node]) {
                path.push_back(i);
                q.push({i, path});
                path.pop_back();
            }
        }
        return ans;
    }
};
