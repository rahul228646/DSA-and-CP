https://leetcode.com/problems/course-schedule-iv/

Time : O(N^2) + O(1)(query time)  Space : O(N^2)

class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            isPrerequisite[pre[0]][pre[1]] = true;
            indegree[pre[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) if(indegree[i] == 0) q.push(i);
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            for(auto& adjnode : adj[node]) {
                for(int i=0; i<numCourses; i++) {
                    if(isPrerequisite[i][node]) isPrerequisite[i][adjnode] = true;
                }
                
                indegree[adjnode]--; 
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }
    
        vector<bool> res;
        for(auto& query : queries) {
            res.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return res;
    }
};
