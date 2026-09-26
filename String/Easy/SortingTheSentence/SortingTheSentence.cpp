#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int,string> mp;
        int i=0;
        while(i<s.size())
        {
            string word="";
            int j =i;
            while(!isdigit(s[i]))
            {
                word+=s[i];
                i++;
            }
            mp[s[i]-'0']=word;
            i+=2;
        }
        vector<pair<int,string>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<int,string>a,pair<int , string>b)
        {
            return a.first<b.first;
        });
        string result="";
        for(auto p:v)
        {
            result+=p.second;
            result+=" ";
        }
        result.pop_back();
        return result;
    }
};
