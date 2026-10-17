#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int>st;
        int n = heights.size();
        for(int i = 0 ;i<n ; i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty())?-1 :st.top();
                max_area = max(max_area , element * (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse = n;
            int element = heights[st.top()];
            st.pop();
            int pse = (st.empty())?-1 :st.top();
            max_area = max(max_area,element*(nse-pse-1));
        }
        return max_area;
    }
};
int main()
{
    vector<int>heights;
    int n;
    cout<<"enter no. of bars in histogram: ";
    cin>>n;
    cout<<"enter heights of bars"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        heights.push_back(x);
    }
    Solution obj;
    cout<<"area of largest rectangle: "<<obj.largestRectangleArea(heights);
    return 0;
}
