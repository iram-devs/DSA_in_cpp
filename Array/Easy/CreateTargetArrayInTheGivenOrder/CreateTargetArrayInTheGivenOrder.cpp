#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i = 0 ;i<nums.size();i++)
        { 
            target.insert(target.begin()+index[i],nums[i]);
        }
        return target;
    }
};
int main()
{
    vector<int> nums {0,3,1,4,5};
    vector<int> index ={0,1,2,3,2};
    Solution obj;
    vector<int> target = obj.createTargetArray(nums , index);
    cout<<"Output: "<<endl;
    for(int x : target)
    {
        cout<<x<<" ";
    }
    return 0;
}