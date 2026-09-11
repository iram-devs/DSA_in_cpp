#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> mp1;
        map<char,char> mp2;
        int i = 0;
        while(i<s.size())
        {
             if(mp1.count(s[i])&&mp1[s[i]]!=t[i]) return false;
             if(mp2.count(t[i])&&mp2[t[i]]!=s[i]) return false;

             mp1[s[i]]=t[i];
             mp2[t[i]]=s[i];
             i++;
        }
        return true;
    }
};
int main()
{
    string s1,s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;

    Solution obj;
    cout<<"Answer: "<<obj.isIsomorphic(s1 , s2);
    return 0;
}