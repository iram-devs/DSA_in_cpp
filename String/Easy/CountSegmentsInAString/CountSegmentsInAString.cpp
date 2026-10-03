#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int cnt=0;
        for(int i =0 ;i<n;i++)
        {
            if(s[i]!=' ' && (i==0 || s[i-1]==' '))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    getline(cin,s);
    Solution obj;
    cout<<"NO. of segments: "<<obj.countSegments(s);
    return 0;
}