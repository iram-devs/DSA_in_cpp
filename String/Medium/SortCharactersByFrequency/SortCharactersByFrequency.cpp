#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char , int > mp;
        for(char ch : s)
        {
            mp[ch]++;
        }
        vector<pair<char , int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a , auto &b)
        {
            return a.second>b.second;
        });
        string ans = "";
        for(pair<char , int> p : v)
        {
            for(int i = 0 ;i<p.second;i++)
            {
                ans+=p.first;
            }
        }
        return ans;
    }
};
int main()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;
    
    Solution obj;
    cout<<"Ans: "<<obj.frequencySort(s);
    return 0;
}