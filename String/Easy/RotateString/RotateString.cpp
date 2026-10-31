#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i = 0;i<s.size();i++)
        {
            if(s==goal) return true;
            s = s.substr(1)+s[0];
        }
        return false;
    }
};
int main()
{
    string s;
    string goal;
    cout<<"Enter string s: ";
    cin>>s;
    cout<<"Enter string goal: ";
    cin>>goal;
    Solution obj;
    cout<<"output: "<<obj.rotateString(s,goal);
    return 0;

}