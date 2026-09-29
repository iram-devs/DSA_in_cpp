#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    string reverseWords(string &s)
    {
       int n = s.size();
       string ans ="";
       while(n>=0)
       {
        if(n>0 && s[n]==' ')
        {
            n--;
        }
        if(n<0) break;
        int end = n;
        while(n>=0 && s[n]!=' ')
        {
            n--;
        }
        int start = n+1;
        if(!ans.empty()) ans+=" ";
        for(int i=start ; i<=end;i++)
        {
            ans+=s[i];
        }
        n--;
       }
       if(!ans.empty() && ans.back()==' ')
       {
        ans.pop_back();
       }
       return ans;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    getline(cin,s);

    Solution obj;
    cout<<"Reversed String: "<<obj.reverseWords(s);
    return 0;

}