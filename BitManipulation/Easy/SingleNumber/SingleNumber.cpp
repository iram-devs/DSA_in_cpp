#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int value:nums)
        {
            ans^=value;
        }
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
    for(int i=0 ;i <n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
    cout<<"Single umber is: "<<obj.singleNumber(nums);
    return 0;
}