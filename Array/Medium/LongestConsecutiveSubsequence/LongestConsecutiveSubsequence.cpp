#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums) s.insert(x);
        int ans = 0;
        for(int x : s)
        {
            if(s.find(x-1)==s.end())
            {
              int curr = x;
              int cnt = 1;
              while(s.find(curr+1)!=s.end())
              {
                curr++;
                cnt++;
              }
            ans = max(ans , cnt);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums;
    cout<<"Enter array elements: "<<endl;
    for(int i =0 ;i<6;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
    cout<<"Longest Continuous Subsequence: "<<obj.longestConsecutive(nums);
    return 0;
}