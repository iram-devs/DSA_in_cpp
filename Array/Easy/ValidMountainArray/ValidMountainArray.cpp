#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
       int largest_element = *max_element(nums.begin(),nums.end());
       if(nums.size()<3) return false;
       int i =0;
       int flag = 1;
       while(i<nums.size()&&nums[i]!=largest_element)
       {
        if(nums[i+1]<=nums[i])
        {
            flag = 0;
        }
        i++;
       } 
       if(i==0 || i==nums.size()-1) return false;
       if(flag)
       {
         while(i<nums.size()-1)
         {
            if(nums[i+1]>=nums[i]) flag = 0;
            i++;
         }
       }
       if(flag==1) return true;
       else return false;
     }
};
int main()
{
    vector<int> v1 = {1,2,4,5,3,1}; 
    vector<int>v2 = {-1 , 2, 4 ,3,3,2};
    
    Solution obj1 , obj2;
    bool ans1 = obj1.validMountainArray(v1);  //true
    bool ans2 = obj2.validMountainArray(v2); //false;

    cout<<ans1<<endl;
    cout<<ans2<<endl;

    return 0;
}