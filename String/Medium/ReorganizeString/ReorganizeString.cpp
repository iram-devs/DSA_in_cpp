#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        for(char c:s) count[c-'a']++;
        priority_queue<pair<int,char>>pq;
        for(int i = 0 ;i<26 ; i++)
        {
            if(count[i]>0) pq.push({count[i],char(i+'a')});
        }
        pair<int,char> prev = {0,'#'};
        string res = "";
        while(!pq.empty())
        {
            auto[cnt , letter] = pq.top();
            pq.pop();
            res+=letter;
            cnt--;
            if(prev.first>0) pq.push(prev);
            prev = {cnt,letter}; 

        }
        return res.size()==s.size()?res :"";
    }
};