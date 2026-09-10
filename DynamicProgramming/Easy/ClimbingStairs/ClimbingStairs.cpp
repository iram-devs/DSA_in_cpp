#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int ways(int n , vector<int>&dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=ways(n-1 , dp) + ways(n-2 , dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ways(n , dp);
    }
};
int main()
{
    int n;
    cout<<"Enter no. of stairs:";
    cin>>n;

    Solution obj;
    cout<<"No. of ways possible to climb "<<n<<" stairs: "<<obj.climbStairs(n);
    return 0;
}