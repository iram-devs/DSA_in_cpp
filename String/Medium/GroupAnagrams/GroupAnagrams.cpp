#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<string>>groupAnagrams(vector<string> &anagrams)
    {
        unordered_map<string , vector<string>>mp;
        for(string str:anagrams)
        {
           string key = str;
           sort(key.begin(),key.end());
           mp[key].push_back(str);
        }
        vector<vector<string>>ans;
        for(pair<string , vector<string>>x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
int main()
{
    vector<string> strs = {"bat","tab","eat","top","not","tea","ton","pot","opt"};
    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);
    for(vector<string> s : ans)
    {
        for(string x : s)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}