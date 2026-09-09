#include<iostream>
using namespace std;
class Solution{
    public:
    int countCommas(int n)
    {
        return max(0,n-999);
    }
};
int main()
{
    int n ;
    cout<<"Enter number:";
    cin>>n;

    Solution obj;
    cout<<"Ans: "<<obj.countCommas(n);
    return 0;
}