#include<iostream>
#include<String>
#include<map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string , char> mp1;
        map<char , string> mp2;
        int i = 0  , j=0;
        while(i<pattern.size() && j<s.size())
        {
            string word = "";
            while(j<s.size() && s[j]!=' ')
            {
                word+=s[j];
                j++;
            }
            if(mp1.count(word) && mp1[word]!=pattern[i]) return false;
            if(mp2.count(pattern[i])&&mp2[pattern[i]]!=word) return false;
            mp1[word]=pattern[i];
            mp2[pattern[i]]=word;
            if(j< s.size())j++;
            i++;
        }
        return i==pattern.size() && j == s.size();
    }
};
int main()
{
    string pattern , s;
    cout<<"Enter Pattern: ";
    cin>>pattern;
    cin.ignore();
    cout<<"Enter String: ";
    getline(cin,s);

    Solution obj;
    cout<<"Output: "<<obj.wordPattern(pattern , s);
    return 0;
    
}