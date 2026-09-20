#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        vector<bool> visited(26,false);
        stack<char>st;
        //counting frequency
        for(char ch:s)
        {
            freq[ch-'a']++;
        }
        for(char ch:s)
        {
            freq[ch-'a']--;
            if(visited[ch-'a']) continue;
            while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0)
            {
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            visited[ch-'a']=true;
        }
        string res="";
        while(!st.empty())
        {
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    Solution obj;
    cout<<"Output: "<<obj.removeDuplicateLetters(s);
    return 0;
}