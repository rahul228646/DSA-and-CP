
#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

//STACK

//Code : Balanced Parenthesis
//  { a + [ b+ (c + d)] + (e + f) }     { a + [ b - c } ]
//  true                                false

bool checkBalanced(char *exp) {
    stack<int> s;
    int len = (int)strlen(exp);
    for(int i =0 ; i<len ; i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            s.push(exp[i]);
        }
        
        else if(s.empty()==true && exp[i] == '}')
            return false;
        
        else if (s.empty()==false){
            if(exp[i] == '}' && s.top() == '{')
                s.pop();
            
        else if(exp[i] == ']' && s.top() == '[')
            s.pop();
            
        else if(exp[i] == ')' && s.top() == '(')
            s.pop();
        }
    }
    
    if(s.empty()== true)
        return true;
    else
        return false;
    
}

//Reverse Stack

void reverseStack_1(stack<int> &input, stack<int> &extra) {
    while(input.empty()==false){
      extra.push(input.top());
      input.pop();
    }
  
    input=extra;
}
// or
void reverseStack_2(stack<int> &input, stack<int> &extra) {
    if(input.size() == 1)
        return ;
    int x = input.top();
    input.pop();
    reverseStack_2(input,extra);
    while(input.empty()==false)
    {
        extra.push(input.top());
        input.pop();
    }
    extra.push(x);
     while(extra.empty()==false)
    {
        input.push(extra.top());
        extra.pop();
    }
    
}

//Check redundant brackets
//    (a + (b*c)) * (d * ( f * j))  (a+b)
//    false                         false

bool checkRedundantBrackets(char *input) {
    int n = (int)strlen(input);
    int count=0;
    stack<int> s;
    int i =0;
    while(i<n)
    {
        if(input[i]!=')')
        {
            s.push(i);
        }
        else
        {
            count=0;
            while(input[s.top()]!='(')
            {
                count++;
                s.pop();
            }
            if(s.empty()==false)
                s.pop();
            if(count==0)
                return true;
        }
            
        i++;
    }
    return false;
}

//Stock Span
/*  For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which has price 2) 
is 2 because minimum count of consecutive days (including 4th day itself) from current day 
which has price less than 4th day is 2 (i.e. day 3 & 4). Similarly, span for 2nd day is 3 
because no stock price in left is greater than 2nd day's price. So count is 3 till 0th day. */

int* stockSpan(int *price, int size) {
    int *arr = new int [size];
    stack<int> s;
    int i =0,j=0;
    while(i<size)
    {
        if(s.empty()==true)
        {
            s.push(i);
            arr[j++]=i+1;
            i++;
         
        }
        else{
            if(price[i]<=price[s.top()])
            {
                arr[j++]=i-s.top();
                s.push(i);
                i++;
              
            }
            else
                s.pop();
        }
    }
    return arr;

}

//Minimum bracket Reversal
//    {{{      {{{{}}
//    -1       1

int countBracketReversals(char input[]){
    int count =0;
    stack<char> s;
    int n = (int)strlen(input);
    if(n%2!=0)
        return -1;
    int  i = 0;
    while(i<n)
    {
        if(input[i]=='{')
        {
            s.push(input[i]);
        }
        
        else if(input[i]=='}')
        {
            if(s.empty()==true)
            {
                s.push(input[i]);
            }
            else
            {
                if(s.top()=='{')
                {
                    s.pop();
                }
                else
                {
                    s.push(input[i]);
                }
            }
        }
        i++;
    }
    while(s.empty()==false){
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();
        if(c1==c2)
            count++;
        if(c1=='{' && c2=='}')
            count += 2;
    }
    return count ;
}

  

// QUEUE

//Reverse Queue
void reverseQueue(queue<int> &q) {
    if(q.size() <= 1)
        return;
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

int main(int argc, const char * argv[]) {
    
}
