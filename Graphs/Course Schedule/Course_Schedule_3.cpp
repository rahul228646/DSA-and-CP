
// https://leetcode.com/problems/course-schedule-iii/
// Time : O(nlogn)
// Space : O(n)

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), time = 0, count = 0;
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){return a[1]<b[1];});
        priority_queue<int> q;
        for(int i = 0; i<n; i++) {
           if((time+courses[i][0]) <= courses[i][1]) {
               time += courses[i][0];
               q.push(courses[i][0]);
               count++;
           }
           else if(!q.empty() && q.top()>courses[i][0]) { // we have to check if any courses which was taken, is larger than the current course, if yes we replace it
                   time -= q.top();
                   q.pop();
                   q.push(courses[i][0]);
                   time += courses[i][0];
             }
          } 
        
        return q.size();
    }
};
// 7 3 

