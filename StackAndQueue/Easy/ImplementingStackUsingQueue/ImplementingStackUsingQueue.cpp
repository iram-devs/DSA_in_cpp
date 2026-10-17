#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x); 
       int n = q.size();
       for(int i=0 ; i<n-1 ; i++)
       {
        q.push(q.front());
        q.pop();
       }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int x = q.front();
        q.pop();
        return x;
   }
    
    int top() {
        if(q.empty()) return -1;
       return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};