#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    void solve(int idx,vector<int>&candidates, int target, vector<int>&ds, vector<vector<int>>&ans, set<vector<int>>&st)
    {
        if(target==0)
        {
            if(st.find(ds)==st.end())
            {
            ans.push_back(ds);
            st.insert(ds);
            }
            return;
        }
        if(idx == candidates.size()) return;
        //pick condition
        if(candidates[idx]<=target)
        {
            ds.push_back(candidates[idx]);
            solve(idx+1, candidates, target-candidates[idx], ds, ans,st);
            ds.pop_back();
        }
        //not pick condition
        int next = idx + 1;
        while (next < candidates.size() &&
               candidates[next] == candidates[idx]) {
            next++;
        }
        solve(next, candidates, target, ds, ans, st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        set<vector<int>>st;
        solve(0, candidates, target, ds, ans, st);
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
    vector<vector<int>>ans = obj.combinationSum2(candidates , target);
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