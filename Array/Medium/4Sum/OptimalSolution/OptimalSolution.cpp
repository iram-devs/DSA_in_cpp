#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int a=0;a<n;a++)
        {
            if(a>0 && nums[a]==nums[a-1]) continue;
            for(int b=a+1 ;b<n;b++)
            {
                if(b>a+1 && nums[b]==nums[b-1]) continue;
                int c = b+1;
                int d = n-1;
                while(c<d)
                {
                  long long sum = nums[a]+nums[b];
                  sum+=nums[c];
                  sum+=nums[d];
                  if(sum>target)d--;
                  else if(sum<target) c++;
                  else
                  {
                    vector<int>temp={nums[a],nums[b],nums[c],nums[d]};
                    ans.push_back(temp);
                    c++;
                    d--;
                    while(c<d && nums[c]==nums[c-1]) c++;
                    while(c<d && nums[d]==nums[d+1]) d--;
                  }
                }
            }
        }
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