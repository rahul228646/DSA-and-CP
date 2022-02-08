//DAG = Directed Acyclic Graph
//https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
void dfs_mod(vector<vector<int>>& graph, vector<vector<int>>& res, int curr_node, vector<int>& path){
    int n = graph.size();
    for(int node : graph[curr_node]){
        path.push_back(node);
        if(node == n-1){
            res.push_back(path);
        }
        dfs_mod(graph, res, node, path);
        path.erase(--path.end());
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    path.push_back(0);
    dfs_mod(graph, result, 0,path);
    return result;
}

};

// or

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
