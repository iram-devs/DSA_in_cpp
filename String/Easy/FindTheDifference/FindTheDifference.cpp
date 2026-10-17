#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>freq(26,0);
        for(char c : t)
        {
            freq[c-'a']++;
        }
        for(char c : s)
        {
            freq[c-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                return i+'a';
            }
        }
        return ' ';
    }
};
int main()
{
    string s,t;
    cout<<"enter string s: ";
    cin>>s;
    cout<<"enter string t: ";
    cin>>t;
    Solution obj;
    cout<<"extra character = "<<obj.findTheDifference(s,t);
    return 0;
}