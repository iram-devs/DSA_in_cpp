#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=tolower(s[i]);
            }
        }
        return s;
    }
};
int main()
{
    string str = "Hello";

    Solution obj;
    string ans = obj.toLowerCase(str);
    cout<<ans;
    return 0;
}