#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0,b=0;
        vector <int> temp;
        while(a<m && b<n )
        {
            if(nums1[a]<nums2[b])
            {
                temp.push_back(nums1[a++]);
            }
            else
            {
                temp.push_back(nums2[b++]);
            }
        }
        while(a<m) temp.push_back(nums1[a++]);
        while(b<n) temp.push_back(nums2[b++]);
        for(int k=0;k<temp.size();k++)
        {
            nums1[k]=temp[k];
        }
        return temp;
        
    }
};
int main()
{
    vector<int> nums1 = {2,4,6,8};
    vector<int> nums2 = {1,3,5,7,9};
    int m = nums1.size();
    int n = nums2.size();
    Solution obj;
    vector <int> ans = obj.merge(nums1, m ,nums2 , n);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}