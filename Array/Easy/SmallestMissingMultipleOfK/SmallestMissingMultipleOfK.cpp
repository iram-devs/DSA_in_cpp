#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int last_element = nums[nums.size()-1];
        int lastpossible = last_element/k + 1;
        for(int i =1 ;i<=lastpossible ;i++)
        {
            int target = k*i;
            if(!(find(nums.begin(), nums.end(), target) != nums.end()))
            {
                return target;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {3,4,6,7,12};
    int k =3;
    Solution obj;
    int ans = obj.missingMultiple(nums , k);
    cout<<ans<<endl;
    return 0;
}