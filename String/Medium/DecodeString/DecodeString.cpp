#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution{
    public:
    string decodeString(string s)
    {
        stack<int> nums;
        stack<char> chars;
        int num=0;
        for(char ch: s)
        {
            if(isdigit(ch))
            {
                num=num*10+(ch-'0');
            }
            else if(ch=='[')
            {
                nums.push(num);
                num=0;
                chars.push(ch);
            }
            else if(ch==']')
            {
                string temp="";
                while(!chars.empty() && chars.top()!='[')
                {
                    
                    temp+=chars.top();
                    chars.pop();
                }
                chars.pop();
                reverse(temp.begin(),temp.end());
                int k = nums.top();
                nums.pop();
                string decoded="";
                while(k--)
                {
                  decoded+=temp;
                }
                for(char ch:decoded)
                {
                    chars.push(ch);
                }
            }
            else{
                chars.push(ch);
            }
        }
        string ans = "";
        while(!chars.empty())
        {
            ans+=chars.top();
            chars.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};
int main()
{
    string s;
    cout<<"Enter encoded string: ";
    cin>>s;

    Solution obj;
    string ans = obj.decodeString(s);
    cout<<"Decoded string: "<<ans<<endl;
    return 0;
}