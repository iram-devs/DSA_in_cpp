#include<iostream>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
   bool isDigit(char ch)
   {
    return (ch>='0' && ch<='9');
   }
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while(i<n && s[i]==' ')
        {
            i++;
        }
        int sign = 1;
        if(i<n && s[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(i<n && s[i]=='+')
        {
            i++;
        }
         long long ans = 0;
         while(i<n && isDigit(s[i]))
         {
            int digit = s[i]-'0';
            ans = ans*10 + digit;
            if(ans*sign > INT_MAX) return INT_MAX;
            else if(ans*sign < INT_MIN) return INT_MIN;
            i++;
         }
         
        return ans*sign;
    }
};
int main()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;

    Solution obj;
    int ans = obj.myAtoi(s);
    cout<<"Output: "<<ans<<endl;
    return 0;  

}