#include<iostream>
using namespace std;
class Solution {
public:
    long long countCommas(long long n) {
        long long ans =0;
        long long p =1000;
        long long commas = 1;
        while(p<=n)
        {
            long long next =p*1000;
            long long last = min(n , next-1);
            ans+=(last-p+1)*commas;
            p=next;
            commas++;
        }
        return ans;
    }
};
int main()
{
    long long n;
    cout<<"Enter no. :";
    cin>>n;
    
    Solution obj;
    cout<<"No. of Commas in range :"<<obj.countCommas(n);
    return 0;
}