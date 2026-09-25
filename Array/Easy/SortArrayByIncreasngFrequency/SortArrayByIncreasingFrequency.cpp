#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<int> sortArray(vector<int>nums)
    {
        vector<int>ans;
        unordered_map<int,int> freq;
        for(int x:nums)
        {
            freq[x]++;
        }
        vector<pair<int,int>>v(freq.begin(),freq.end());
        sort(v.begin(),v.end(),[](pair<int,int>a , pair<int,int>b)
    {
        if(a.second==b.second) return a.first>b.first;
        return a.second<b.second;
    });
    for(auto p:v)
    {
        for(int i=0;i<p.second;i++)
        {
            ans.push_back(p.first);
        }
    }
    return ans;
    }
};
int main()
{
    vector<int>nums = {1,2,3,1,2,4,1,3,2,4,1,3};
    Solution obj;
    vector<int> ans = obj.sortArray(nums);
    cout<<"Sorted array: "<<endl;
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}