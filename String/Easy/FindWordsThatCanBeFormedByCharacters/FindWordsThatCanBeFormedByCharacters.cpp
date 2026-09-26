#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool goodstring(string s , vector<int> v)
    {
        for(char ch: s)
        {
            if(!v[ch-'a']) return false;
            v[ch-'a']--;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26,0);
        int length=0;
        for(char ch: chars)
        {
            mp[ch-'a']++;
        }
        for(string s:words)
        {
            if(goodstring(s,mp)==true)
            {
                length+=s.size();
            }
        }
        return length;
    }
};
int main()
{
    vector<string> words = {"hat","bt","rats","clap"};
    string chars = "sheepandhensarestanding";
    Solution obj;
    int ans = obj.countCharacters(words , chars);
    cout<<"Output: "<<ans<<endl;
    return 0;

}