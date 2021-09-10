
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// min priority queue implementation
class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    int getSize() {
        return (int)pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;        // Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex =(int) pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
   int removeMin() {
       if(isEmpty()){
           return 0;
       }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
       pq.pop_back();
            int parentIndex = 0;
            int LchildIndex = 2* parentIndex + 1;
            int RchildIndex = 2* parentIndex + 2;
            
        while(LchildIndex < pq.size()){
            int minIndex = parentIndex;
           
            
            if(pq[minIndex] > pq[LchildIndex]){
                minIndex = LchildIndex;
            }
        
            if(RchildIndex < pq.size() && pq[minIndex] > pq[RchildIndex]){
                minIndex = RchildIndex;
            }
            
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = minIndex;
            LchildIndex = 2* parentIndex + 1;
            RchildIndex = 2* parentIndex + 2;
        }
        return ans;
    }
};

//Code : K smallest Elements
//    13
//    2 12 9 16 10 5 3 20 25 11 1 8 6
//    4
//--> 5 3 2 1

vector<int> kSmallest(int *input, int n, int k) {
    vector<int> out;
    
    priority_queue<int> pq;  // by default c++ has max-heap for min heap use priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    }
    
    for(int i=k; i<n; i++){
        if(pq.top() > input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    for(int i=0; i<k; i++){
        out.push_back(pq.top());
        pq.pop();
    }

    return out;
}

//Buy the ticket
//    3
//    3 9 4
//    2
//--> 2
//Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status : {9, 4, 3}. Time : 0 secs.
//Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status : {4, 3}. Time : 1 secs.
//Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.

int buyTicket (int *arr, int n, int k){
  
    priority_queue<int> pq;
    queue<int> q;
    int time=0;
    
    for(int i = 0; i<n; i++){
        q.push(i);
        pq.push(arr[i]);
    }
    
    while(1){
        if(arr[q.front()] == pq.top()){
            time++;
            if(q.front()==k){
                return time;
            }
            pq.pop();
            q.pop();
        }
        else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
}

//Running median
//    6
//    6 2 1 3 7 5
//    6 4 2 2 3 4

void findMedian(int arr[], int n){
  
 
    priority_queue<int> s;

    priority_queue<int,vector<int>,greater<int> > g;
  
    int med = arr[0];
    s.push(arr[0]);
  
    cout << med << endl;
  
 
    for (int i=1; i < n; i++)
    {
        int x = arr[i];
  
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top())/2.0;
        }

        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (int)s.top();
            }
            else
            {
                g.push(x);
                med = (int)g.top();
            }
        }

        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
  
            med = (s.top() + g.top())/2.0;
        }
  
        cout << med << endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
