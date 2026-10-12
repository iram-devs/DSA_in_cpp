#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            if(i==0 || intervals[i][0]>ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0)
        {
          intervals.push_back(newInterval);
          return intervals;
        }
        if(newInterval[0]<=intervals[0][0])
        {
            intervals.insert(intervals.begin()+0,newInterval);
            return merge(intervals);
        }
        if(newInterval[0]>intervals[n-1][1])
        {
            intervals.push_back(newInterval);
            return merge(intervals);
        }
        for(int i = 0 ; i<n ; i++)
        {
           
            if(newInterval[0]<=intervals[i][1])
            {
                 intervals[i][1] = max(intervals[i][1], newInterval[1]);
                 return merge(intervals);
            }
             else
             {
                intervals.insert(intervals.begin()+i,newInterval);
                return merge(intervals);
             }
        }
        return {{}};
    }
};
int main()
{
    vector<vector<int>>intervals = {{1,4},{5,6},{7,10},{11,14}};
    vector<int>newInterval;
    cout<<"enter new interval:"<<endl;
    for(int i=0 ; i<2 ; i++)
    {
        int x;
        cin>>x;
        newInterval.push_back(x);
    }
    Solution obj;
    vector<vector<int>> ans =  obj.insert(intervals,newInterval);
    cout<<"intervals after insertion: "<<endl;
    for(vector<int> x : ans)
    {
        for(int y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}