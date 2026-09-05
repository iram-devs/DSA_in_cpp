#include<iostream>
#include<string>
using namespace std;
//Find the first occurrence od needle in haystack
class Solution{
    public:
    int strStr(string &haystack , string &needle)
    {
        if(haystack.size() < needle.size()) return -1;
        for(int i = 0 ;i<haystack.size();i++)
        {
            int j = 0;
            while(j<needle.size())
            {
                if(needle[j] != haystack[i+j])
                {
                    break;
                }
                j=j+1;
            }
            if(j==needle.size()) return i;
        }
        return -1;
    }
};
int main()
{
    string needle = "sad";
    string haystack = "assadbadnotsad";

    Solution obj;
    int ans = obj.strStr(haystack , needle);
    cout<<ans<<endl; //2
    return 0;
}