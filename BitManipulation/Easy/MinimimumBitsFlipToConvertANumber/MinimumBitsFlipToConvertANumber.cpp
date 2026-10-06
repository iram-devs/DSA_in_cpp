#include<iostream>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        unsigned int s = static_cast<unsigned int>(start);
        unsigned int g = static_cast<unsigned int>(goal);
        unsigned int ans = s^g;
        int cnt=0;
        while(ans!=0)
        {
          cnt+=(ans & 1u);
          ans>>=1;
        }
        return cnt;
    }
};
int main()
{
    int start,goal;
    cout<<"Enter start: ";
    cin>>start;
    cout<<"Enter goal: ";
    cin>>goal;
    Solution obj;
    cout<<"No. of bits to flip: "<<obj.minBitFlips(start,goal);
    return 0;
}
