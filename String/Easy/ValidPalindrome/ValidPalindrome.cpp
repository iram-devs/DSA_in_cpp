#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    bool isAlphanumeric(char ch)
    {
       return(ch >= 'A' && ch <='Z' || ch>='a' && ch<='z');
    }
    bool isPalindrome(string s)
    {
        string str;
        for(char ch:s)
        {
            if(isAlphanumeric(ch)) str+= tolower(ch);
        }
        int lo = 0 , hi = str.size()-1;
        while(lo<=hi)
        {
            if(str[lo]!=str[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
};
int main()
{
    string str1 = "Abc#ba";
    string str2 = "Ab#ca#b";

    Solution obj1 , obj2;
    bool ans1 = obj1.isPalindrome(str1); //true
    bool ans2 = obj2.isPalindrome(str2); //false

    cout<<ans1<<endl;
    cout<<ans2<<endl;

}