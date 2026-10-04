#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        for(char ch:s)
        {
            if(!st.empty() && st.top()==ch) st.pop();
            else st.push(ch);
        }
        while(!st.empty())
        {
          ans = st.top()+ans;
          st.pop();
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
    cout<<"String after removing adj duplicates: "<<obj.removeDuplicates(s);
    return 0;
}
