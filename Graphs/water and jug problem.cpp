https://leetcode.com/problems/water-and-jug-problem/submissions/

class Solution {
public:
  
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_map<int, bool> seen;
        queue<int> q;
//      fill jug1 fill jug2 empty jug1 empty jug2  
        vector<int> capacities = {jug1Capacity, jug2Capacity, -jug1Capacity, -jug2Capacity};
        q.push(0);
        while(!q.empty()) {
            int curr = q.front();
            if(curr == targetCapacity) return true;
            q.pop();
            seen[curr] = true;
            for(auto i : capacities) {
                int nxtState = i+curr;
                nxtState = max(0, nxtState); // nxtState cannot be negative
                nxtState = min(jug1Capacity + jug2Capacity, nxtState); // // nxtState cannot be greater than the sum of individual jugs
                if(seen.find(nxtState) == seen.end()) q.push(nxtState);
            }
        }
        return false;
    }
};


