#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
        int i =0;
        int maxdepth = 0;
        int depth = 0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                depth++;
                maxdepth = max(maxdepth , depth);
            }
            if(s[i]==')'&& !st.empty() && st.top()=='(')
            {
                st.pop();
                depth--;
            }
            i++;
        }
        return maxdepth;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution obj;
    int ans = obj.maxDepth(s);
    cout<<"max depth: "<<ans<<endl;
    return 0;
}