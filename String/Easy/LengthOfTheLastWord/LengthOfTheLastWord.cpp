#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    int lengthOfLastWord(string &s)
    {
      int n = s.size();
      int i = n-1;
      int length=0;
      //to skip spaces in the last
      while(i>=0 && s[i]==' ') i--;
      while(i>=0 && s[i]!=' ')
      {
         length++;
         i--;
      }
      return length;
    }
};
int main()
{
    string s = "Hi My Name is Shambhavi  ";
    Solution obj;
    int ans = obj.lengthOfLastWord(s);
    cout<<ans<<endl;
    return 0;
}