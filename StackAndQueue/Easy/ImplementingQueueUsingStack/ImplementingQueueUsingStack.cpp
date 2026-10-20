#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class QueueUsingStacks {
private:
 stack <int>outstk;
 stack <int>instk;
 
    
public:
    void pushElement(int x) {
        instk.push(x);
    }
    int popElement() {
        if(outstk.empty())
        {
            while(!instk.empty())
            {
                outstk.push(instk.top());
                instk.pop();
            }
        }
        int val = outstk.top();
        outstk.pop();
        return val;
    }
    int peekElement() {
        if(outstk.empty())
        {
            while(!instk.empty())
            {
                outstk.push(instk.top());
                instk.pop();
            }
        }
        return outstk.top();
    }
    bool isEmptyResult() {
        return instk.empty()&&outstk.empty();
    }
};
