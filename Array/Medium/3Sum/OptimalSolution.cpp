#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>&nums)
    {
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++)
        {
            set<int> s;
            for(int j=0 ;j<nums.size();j++)
            {
                int third = -(nums[i]+nums[j]);
                if(s.find(third)!=s.end())
                {
                    vector<int>temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                s.insert(nums[j]);
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
    vector<vector<int>>ans = obj.threeSum(nums);
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