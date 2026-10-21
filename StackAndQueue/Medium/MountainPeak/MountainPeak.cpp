#include<iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> next_higher_peak(vector<int>& heights) {
    // Write you code here
    int n = heights.size();
    vector<int>ans(n,0);
    stack<int>st;
    for(int i = n-1 ; i>=0 ;i--)
    {
       while(!st.empty() && st.top()<=heights[i])
       {
           st.pop();
       }
       ans[i]=(st.empty()) ?-1 :st.top();
       st.push(heights[i]);
    }
    return ans;
}