#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void helper(vector <string>&v, int n, int oc,int cc,string s)
    {
        if(oc==n && cc==n)
        {
            v.push_back(s);
        }
        if(oc<n){
            helper(v,n,oc+1,cc,s+"(");
        }
        if(cc <oc)
        {
            helper(v,n,oc,cc+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> s;
        int oc=0 , cc=0;
        helper(s,n,oc,cc,"");
        return s;
    }
};
int main()
{
    int n;
    cout<<"Enter no. of pairs: ";
    cin>>n;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    cout<<"Possible combinations are"<<endl;
    for(string s: ans)
    {
        cout<<s<<endl;
    }
  return 0;
}