#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                if(ans.empty() || ans.back()!= nums1[i]){
                ans.push_back(nums1[i]);
                }
                 i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int>nums1 = {1,2,3,3,4,5,6,9,9};
    vector<int>nums2 = {3,3,5,4,7,11,9,10};
    Solution obj;
    vector <int> ans = obj.intersection(nums1 , nums2);
    for(int x :ans)
    {
        cout<<x<<" ";
    }
    return 0;
}