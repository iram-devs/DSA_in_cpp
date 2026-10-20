#include<iostream>
#include<stack>
using namespace std;
class CustomStack {
    stack<int>s1;
    stack<int>s2;
    int size;
    int maxsize;
public:
    CustomStack(int maxSize) {
        size = 0;
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(s1.size()==maxsize) return;
        else
        {
             s1.push(x);
             size++;
        }
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int val = s1.top();
        s1.pop();
        size--;
        return val;
    }
    
    void increment(int k, int val) {
        if(s1.size()>k)
        {
            int i = 0;
            while(i<s1.size()-k)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        while(!s1.empty())
        {
            s2.push(s1.top()+val);
            s1.pop();
        }
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */