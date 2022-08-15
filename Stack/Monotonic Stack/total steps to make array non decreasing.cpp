// https://leetcode.com/contest/weekly-contest-295/problems/steps-to-make-array-non-decreasing/
// https://www.youtube.com/watch?v=NQGduRE1Crk

class Solution {
public:
    using pr = pair<int, int>;
    int totalSteps(vector<int>& arr) {
        stack<pr> st;
        int n = arr.size(), ans = 0;
        st.push({arr[n-1], 0}); // element and no of elements deleted on its right
        for(int i = n-2; i>=0; i--) {
            int count = 0;
            while(!st.empty() && arr[i] > st.top().first) {
                count = max(count+1, st.top().second);
                st.pop();
            }
            ans = max(ans, count);
            st.push({arr[i], count});
        }
        return ans;
    }
};


eg - > 
  
  10 1 2 5 6 1 2 3
  
  iterating from back -
  
                                     {1, 0} 
         {1, 0}               {2, 0} {2, 0} 
         {2, 0}        {5, 0} {5, 0} {5, 0} 
 {3, 0}  {3, 0} {6, 3} {6, 3} {6, 3} {6, 3} {10, 4}

  
  

FIrst rephrase the problem.
Big eats small.
What is maximum number of right elements an element can eat.
Take a example [15,14,13]
It seems 15 can eat 2 elements, but 14 will eat 13 while 15 is eating 14.
Hence answer is 1
Take another example [16,15,13,14]
While 16 is eating 15, 15 will eat 13 and 14 will be left to be eaten by 16.
Hence answer is 2.
Take another example [16,4,5,6,13,12]
While 16 will eat 4,5 and 6, 13 would have already eaten 12, hence answer is 4.

We maintain a stack which stores elements in decreasing order from back.
WHY? Because if some biggger number comes, it will eat smaller ones and we will do some calculations there.
WHAT calculations? If current element is bigger than top of stack, what does it mean?
It can eat it, so what will be answer? Max of number of elements already eaten by current element + 1 and max elements that top of stack can eat if current element doesn't eat it.


