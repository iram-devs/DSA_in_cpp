#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        stack<string> st;
        while(i<path.size())
        {
            if(path[i]=='/')
            {
                i++;
                continue;
            }
            string dir = "";
            while(i<path.size() && path[i]!='/')
            {
                dir+=path[i];
                i++;
            }
            if(dir == "." )
            {

            } 
            else if (dir == "..")
            {
                if(!st.empty())
                {
                  st.pop();
                }
            }
            else
            {
                st.push(dir);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans = '/'+st.top()+ans;
            st.pop();
        }
        if(ans=="")
        {
            return "/";
        }
        return ans;
    }
};
int main()
{
    string path;
    cout<<"Enter unix file path: ";
    cin>>path;

    Solution obj;
    string ans = obj.simplifyPath(path);
    cout<<"Simplified Path: "<<ans<<endl;
    return 0;
}