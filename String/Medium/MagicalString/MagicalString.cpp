#include<iostream>
#include<string>
using namespace std;
 class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i=2;
        int num = 1;
        if(n<=0) return 0;
        if(n<=3) return 1;
        while(s.size()<n)
        {
            for(int j=0;j<s[i]-'0';j++)
            {
                s+=to_string(num);
            }
            if(num==1)num=2;
            else num=1;
            i++;
        }
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='1') cnt++;
        }
        return cnt;
    }
};
int main()
{
    int n;
    cout<<"Enter the integer: ";
    cin>>n;
    Solution obj;
    cout<<"No. of 1s: "<<obj.magicalString(n);
    return 0;
}