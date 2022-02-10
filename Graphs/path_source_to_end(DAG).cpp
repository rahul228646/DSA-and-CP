//DAG = Directed Acyclic Graph
//https://leetcode.com/problems/all-paths-from-source-to-target/

// DFS
// Time : O(2^V⋅V)
// Space : O(2^V⋅V)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int start, int end) {
        path.push_back(start);
        if(start == end) {
            result.push_back(path);
        }
        else {
            for(auto i : graph[start]) dfs(graph, i, end);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {\
        dfs(graph, 0, graph.size()-1);
        return result;
    }
};

// BFS 
// [[4,3,1],[3,2,4],[3],[4],[]]
// [[0,4],[0,3,4],[0,1,4],[0,1,3,4],[0,1,2,3,4]] --- BSF output, notice first path is the smallest.
// Time : O(2^V⋅V)
// Space : O(2^V⋅V)
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


