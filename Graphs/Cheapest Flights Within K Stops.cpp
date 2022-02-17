// https://www.youtube.com/watch?v=5eIK3zUdYmE
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Time : O(EV)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n+1, INT_MAX);
        cost[src] = 0;
        for(int i = 0; i<=k; i++) {
            vector<int> temp = cost;
            for(auto j : flights) {
                int s = j[0], d = j[1], c = j[2];
                if(cost[s] != INT_MAX && temp[d] > cost[s]+c) {
                    temp[d] = cost[s]+c;
                }
            }
            cost = temp;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
        
    }
};
