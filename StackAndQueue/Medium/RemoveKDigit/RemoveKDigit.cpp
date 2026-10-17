#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        if(k>=num.size()) return "0";
        for(int i = 0; i<num.size();i++)
        {
            while(!st.empty() && k>0 && st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //if string is traversed ans every element is in increasing order
        while(!st.empty()&&k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.size()==0) return "0";
        else return ans;
        
    }
};
int main()
{
    string s;
    cout<<"enter string of numbers:"<<endl;
    cin>>s;
    int k;
    cout<<"enter no. of digits to be removed:"<<endl;
    cin>>k;
    Solution obj;
    cout<<"output: "<<obj.removeKdigits(s,k);
    return 0;
}