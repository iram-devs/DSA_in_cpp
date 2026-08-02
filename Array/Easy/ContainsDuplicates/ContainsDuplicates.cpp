#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dupe=-1;
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]==nums[i-1])
          {
            dupe=1;
          }
        }
        if (dupe==-1){
            return false;
        }
        else{
            return true;
        }
    }
};
int main()
{
  vector<int> nums  = {1,4,3,4,5};
  Solution obj ;
  bool ans = obj.containsDuplicate(nums);
  cout<<ans<<endl;
  return 0;
}
     