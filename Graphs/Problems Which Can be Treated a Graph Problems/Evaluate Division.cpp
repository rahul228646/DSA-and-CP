// https://leetcode.com/problems/evaluate-division/
// directed graph
class Solution {
public:
    
    double dfs(unordered_map<string,unordered_map<string, double>>& graph, string start, string end, unordered_set<string>& visited) {
      
        if(graph[start].find(end) != graph[start].end()) return graph[start][end];
        visited.insert(start);
      
        for(auto i : graph[start]) {
            if(graph.find(i.first) != graph.end() && visited.find(i.first) == visited.end()) {
                visited.insert(i.first);
                double temp = dfs(graph, i.first, end, visited);
                if(temp != 0) return i.second * temp;
            }
        }
        return 0;
        
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        
      // build graph [a, b] [b c]
      //             [w1]   [w2]
      //   a-(w1)-b-(w2)-c &&  c-(1/w2)-b-(1/w1)-a  && a-(1)-a && b-(1)-b && c-(1)-c
      
        unordered_map<string,unordered_map<string, double>> graph;
        
        for (int i = 0; i <val.size(); ++i){
            graph[eq[i][0]].insert({eq[i][1],val[i]});
            graph[eq[i][0]].insert({eq[i][0],1});
            graph[eq[i][1]].insert({eq[i][0],1/val[i]});
            graph[eq[i][1]].insert({eq[i][1],1});
        }
    
        vector<double> ans;
        for(auto i : q) {
            string start = i[0];
            string end = i[1];
            double res = 0;
            unordered_set<string> visited;
          
            if(graph.find(start) != graph.end() && graph.find(end) != graph.end())
                res = dfs(graph, start, end, visited);
          
            if(res) ans.push_back(res);
            else ans.push_back(-1);
        }
        return ans;
    }
};

