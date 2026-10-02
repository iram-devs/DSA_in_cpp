#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isVowel(char s)
    {
        return(s=='a'||s=='e'||s=='i'||s=='o'||s=='u');
    }
    int maxVowels(string s, int k) {
     int cnt=0;
      for(int i=0;i<k;i++)
      {
        if(isVowel(s[i])) cnt++;
      }
      int ans = cnt;
      for(int i=k;i<s.size();i++)
      {
        if(isVowel(s[i-k])) cnt--;
        if(isVowel(s[i])) cnt++;
        ans = max(ans,cnt);
      }
      return ans;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int k;
    cout<<"Enter length of substring: ";
    cin>>k;
    Solution obj;
    cout<<"Max no. of Vowels: "<<obj.maxVowels(s,k);
    return 0;
}