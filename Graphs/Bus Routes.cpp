https://www.youtube.com/watch?v=WhuiqhMXhxM&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=8
https://leetcode.com/problems/bus-routes/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int, vector<int>> stops_visited_by_ith_bus;
        for(int i = 0; i<routes.size(); i++) {
            for(int j = 0; j<routes[i].size(); j++) {
                stops_visited_by_ith_bus[routes[i][j]].push_back(i);
            }
        }
        unordered_map<int, bool> stops_visited, bus_no_visited;
        queue<int> q;
        stops_visited[source] = true;
        q.push(source);

        int dist = 0;
        while(q.size()) {
            int sz = q.size();
            ;
            while(sz--) {
                int curr = q.front();
                q.pop();
                if(curr == target) return dist;
                for(auto i : stops_visited_by_ith_bus[curr]) {
                    if(bus_no_visited.find(i) != bus_no_visited.end()) continue;
                    else {
                        auto stops = routes[i];
                        bus_no_visited[i] = true;
                        for(auto s : stops) {
                            if(stops_visited.find(s) != stops_visited.end()) continue;
                            else {
                                q.push(s);
                                stops_visited[s] = true;
                            }
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

