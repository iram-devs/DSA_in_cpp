#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int getsum(vector<int> v)
    {
        int sum = 0;
        for(int x : v)
        {
            sum+=x;
        }
        return sum;
    }
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ;i <accounts.size();i++)
        {
            sum = getsum(accounts[i]);
            maxi = max(maxi , sum);
        }
        return maxi;
    }
};
int main()
{
    vector<vector<int>> accounts = {{1,2,3},{3,4,1},{1,2},{2,3,2}};
    Solution obj;
    int ans = obj.maximumWealth(accounts);
    cout<<ans<<endl;
    return 0;
}