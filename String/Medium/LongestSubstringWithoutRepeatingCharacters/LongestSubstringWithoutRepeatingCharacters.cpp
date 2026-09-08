#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int LengthOfLongestSubstring(string &s)
    {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;
        for(int right = 0; right<s.size();right++)
        {
            while(charSet.count(s[right]))
            {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};
int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    Solution obj;
    int ans = obj.LengthOfLongestSubstring(s);
    cout<<"Length:\t"<<ans<<endl;
    return 0;
}