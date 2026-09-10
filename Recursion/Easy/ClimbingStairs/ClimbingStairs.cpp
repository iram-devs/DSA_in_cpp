#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
       if(n==0) return 1;
       if(n<0) return 0;

       return climbStairs(n-1)+climbStairs(n-2);
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