#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solve (int idx , vector<int>&candidates , int target , vector<int>&ds , vector<vector<int>>&ans)
    {
           if(target==0)
           {
            ans.push_back(ds);
            return;
           }
           if(idx == candidates.size())
           {
            return;
           }
           //pick condition
           if(candidates[idx]<=target)
           {
            ds.push_back(candidates[idx]);
            solve(idx , candidates , target-candidates[idx],ds,ans);
            ds.pop_back();
           }
           //not pick condition
           solve(idx+1 , candidates , target , ds , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve (0 , candidates , target , ds, ans);
        return ans;
    }
};
int main()
{
    int n;
    cout<<"enter size of candidate array: ";
    cin>>n;
    vector<int>candidates;
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        candidates.push_back(x);
    }
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    Solution obj;
    vector<vector<int>>ans = obj.combinationSum(candidates , target);
    cout<<"output:"<<endl;
    for(vector<int> arr : ans)
    {
        for(int x : arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}