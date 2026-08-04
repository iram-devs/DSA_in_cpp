#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n ; i++)
        {
             int leftsum =0 ;
             int rightsum=0;
            for(int j = 0; j< i ;j++)
            {
              leftsum+=nums[j];
            }
            for(int k = i+1 ; k<n ;k++)
            {
                rightsum += nums[k];
            }
            if(leftsum == rightsum)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
  vector<int> nums = {1,3,4,1,2,3,3};
  Solution obj;
  int ans = obj.pivotIndex(nums);
  cout<<ans<<endl;
  return 0;
}