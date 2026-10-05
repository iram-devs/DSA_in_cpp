#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        unsigned int bits = static_cast<unsigned int>(n);
        int cnt=0;
        while(bits)
        {
            if(bits & 1u) cnt++;
            bits>>=1;
        }
        return cnt;
    }
};
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Solution obj;
    cout<<"Number of 1s: "<<obj.hammingWeight(n);
    return 0;
}