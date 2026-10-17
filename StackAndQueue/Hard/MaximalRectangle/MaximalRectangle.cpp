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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //column
        int max_area = 0;
        vector<vector<int>> prefixSum(n,vector<int>(m,0));
        for(int j = 0 ; j<m ;j++)
        {
            int sum = 0;
            for(int i = 0; i<n ; i++)
            {
                if(matrix[i][j]=='1') sum++;
                else sum=0;
                prefixSum[i][j]=sum;
            }
        }
        for(int i = 0 ; i < n ;i++)
        {
           max_area = max(max_area ,largestRectangleArea(prefixSum[i]));
        }
        return max_area;
    }
};
int main()
{
    vector<vector<char>>matrix{{'1','0','1','0','1'},
                              {'1','0','1','1','1'},
                              {'1','1','1','1','1'},
                              {'1','0','0','1','0'}};
    Solution obj;
    cout<<"ans:"<<obj.maximalRectangle(matrix);
    return 0;

}