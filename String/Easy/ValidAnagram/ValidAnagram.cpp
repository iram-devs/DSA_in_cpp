#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool validAnagram(string &s , string &t)
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        transform(t.begin(),t.end(),t.begin(),::tolower);
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        t.erase(remove(t.begin(),t.end(),' '),t.end());
        vector<int> count(26,0);
        for(char ch : s)
        {
            count[ch - 'a']++;
        }
        for(char ch:t)
        {
            count[ch-'a']--;
        }
        for(int x : count)
        {
            if (x != 0) return false;
        }
       return true;
    }
};
int main()
{
    string s ="anagram";
    string t ="nagaram";
    Solution obj;
    bool ans = obj.validAnagram(s,t);
    cout<<ans<<endl;
    return 0;
}