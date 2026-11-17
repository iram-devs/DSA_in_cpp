#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string res="";
        int cnt = 0;
        int i=0;
        while(cnt<k)
        {
            string word;
            while(i<s.size()&& s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            res+=word+' ';
            i++;
            cnt++;
        }
        res.pop_back();
        return res;
    }
};