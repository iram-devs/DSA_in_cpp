#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char , int> mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        vector<pair<char ,int>> v(mp.begin(),mp.end());
        for(int i=1;i<v.size();i++)
        {
           if(v[i].second != v[i-1].second) return false;
        }
        return true;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    Solution obj;
    bool ans = obj.areOccurrencesEqual(s);
    cout<<"output: "<<ans<<endl;
    return 0;
}
