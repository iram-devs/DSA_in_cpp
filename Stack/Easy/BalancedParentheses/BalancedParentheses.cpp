#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution{
    public:
    bool check(string s)
    {
        stack<char>st;
        for(char ch: s)
        {
            if(ch=='('||ch=='{'||ch=='[') st.push(ch);
            else
            {
                if(st.empty())return false;
                if((ch==')' && st.top()!='(')||( ch=='}' && st.top()!='{') ||( ch==']' && st.top()!='[')) return false;
                st.pop();           
            }
        }
        return st.empty();
    }
};
int main()
{
    string s;
    cout<<"Enter string of parenthesis: "<<endl;
    cin>>s;

    Solution obj;
    if(obj.check(s)==1) cout<<"Parenthesis valid!"<<endl;
    else cout<<"Parenthesis invalid"<<endl;
    return 0;
}