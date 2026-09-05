#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool canConstruct(string &ransomNote , string &magazine)
    {
       transform(ransomNote.begin(),ransomNote.end(),ransomNote.begin(),::tolower);
       transform(magazine.begin(),magazine.end(),magazine.begin(),::tolower);

       vector<int> count(26,0);
       for(char ch : magazine)
       {
        count[ch - 'a']++;
       }
       for(char ch:ransomNote)
       {
        if(count[ch - 'a']==0) return false;
        count[ch - 'a']--;
       }
      return true;
    }
};
int main()
{
    string ransomNote = "aa";
    string magazine = "aabs";
    Solution obj;
    bool ans = obj.canConstruct(ransomNote,magazine);
    cout<<ans<<endl;
    return 0;
}