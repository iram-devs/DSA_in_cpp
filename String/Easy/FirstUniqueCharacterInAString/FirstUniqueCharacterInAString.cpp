#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int FirstUniqueChar(string &s)
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        vector<int> count(26,0);
        for(char ch: s)
        {
            count[ch-'a']++;
        }
        for(int i = 0 ;i<s.size();i++)
        {
            if(count[s[i]-'a']==1)
            {
                return i;
                break;
            }
        }
        return -1;
    }
};
int main()
{
    string s = "Leetcodelove";
    Solution obj;
    int ans = obj.FirstUniqueChar(s);
    cout<<ans<<endl;
    return 0;

}