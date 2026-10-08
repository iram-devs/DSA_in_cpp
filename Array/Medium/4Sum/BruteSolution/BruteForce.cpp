#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
         set<vector<int>>st;
         int n = nums.size();
         for(int a=0 ; a<n ; a++)
         {
            for(int b = a+1 ; b<n ;b++)
            {
                for(int c = b+1 ; c<n ;c++)
                {
                    for(int d=c+1 ; d<n ;d++)
                    {
                        long long sum = nums[a]+nums[b];
                        sum+=nums[c];
                        sum+=nums[d];
                        if(sum==target)
                        {
                            vector<int> temp = { nums[a],nums[b],nums[c],nums[d]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
         }
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;
    }
};
int main()
{
    vector<int> nums;
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter elements"<<endl;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int target;
    cout<<"enter target: ";
    cin>>target;
    Solution obj;
    vector<vector<int>>ans = obj.fourSum(nums,target);
    cout<<"Output: "<<endl;
    for(vector<int> v:ans)
    {
        for(int x: v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}