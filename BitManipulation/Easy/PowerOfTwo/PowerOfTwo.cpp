#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        //find pos of leftmost set bit
        unsigned int bits = static_cast<unsigned int>(n);
        if(n<=0) return false;
        return ( bits & (bits-1))==0;
     }
};
int main()
{
    int n ;
    cout<<"Enter no. : ";
    cin>>n;
    Solution obj;
    cout<<"Output: "<<obj.isPowerOfTwo(n);
    return 0;
}