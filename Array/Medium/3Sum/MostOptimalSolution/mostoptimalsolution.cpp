#include<iostream>
#include<vector>
#include<set>
#include<Algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0) k--;
                else if (sum<0) j++;
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    st.insert(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
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