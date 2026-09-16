#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> findAnagrams(string p , string s)
    {
       int n = p.length();
       int m = s.length();
       vector<int> freq1(26,0);
       vector<int> freq2(26,0);
       vector<int> ans;
       for(int i = 0 ;i<n ;i++)
       {
        freq1[p[i]-'a']++;
        freq2[s[i]-'a']++;
       }
       if(freq1==freq2) ans.push_back(0);
       for(int i = n ; i<m ;i++)
       {
         freq2[s[i]-'a']++;
         freq2[s[i-n]-'a']--;
         if(freq1==freq2) ans.push_back(i-n+1);
       }
       return ans;
    }
};
int main()
{
    string p , s;
    cout<<"Enter first string: ";
    cin>>p;
    cout<<"Enter second string: ";
    cin>>s;

    Solution obj;
    vector<int> ans = obj.findAnagrams(p , s);
    for(int x :ans)
    {
        cout<<x<<" ";
    } 
    return 0;
}