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
};
int main()
{
    vector<vector<int>>intervals;
    int n;
    cout<<"Enter no. of intervals: ";
    cin>>n;
    cout<<"enter "<<n<< " intervals:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cout<<"start: ";
        cin>>x;
        cout<<"end: ";
        cin>>y;
        intervals.push_back({x,y});
    }
    Solution obj;
    vector<vector<int>>ans = obj.merge(intervals);
    cout<<"Output: "<<endl;
    for(vector<int>v:ans)
    {
        for(int x: v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}