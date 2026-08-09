#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>,greater<int>> pq;
        for(int x :nums)
        {
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};
int main()
{
    vector<int>nums={1,2,2,3,5,4,6,1};
    Solution obj;
    int ans = obj.findKthLargest(nums , 2);
    cout<<ans<<endl;
    return 0;
}