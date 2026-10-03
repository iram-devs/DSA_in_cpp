#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int>st;
        if(s.size()==0) return 0;
        st.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else 
                {
                    ans = max(ans,i - st.top());
                }
            }
        }
        return ans;

    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    Solution obj;
    cout<<"Length of longest valid parentheses: "<<obj.longestValidParentheses(s);
    return 0;
}