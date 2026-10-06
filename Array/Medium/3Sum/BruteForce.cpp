#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>>ThreeSum(vector<int>&nums)
    {
        set<vector<int>>st;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j=i+1 ; j<nums.size();j++)
            {
                int sum = 0;
                for(int k=j+1;k<nums.size();k++)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    {
                        vector<int>temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
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
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
    vector<vector<int>>ans = obj.ThreeSum(nums);
    cout<<"Output: "<<endl;
    for(vector<int> v: ans)
    {
        for(int x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}