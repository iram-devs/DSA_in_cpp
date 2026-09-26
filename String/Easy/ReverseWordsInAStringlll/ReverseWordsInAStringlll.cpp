#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
         int start=0;
         int n=s.length();
         for(int i=0;i<=n;i++)
         {
            if(s[i]==' '|| i==n)
            {
                int end=i-1;
                while(start<end)
                {
                swap(s[start],s[end]);
                start++;
                end--;
                }
                start=i+1;

            }
         }
         return s;
    }
};
int main()
{
    string s;
    cout<<"Enter string: ";
    getline(cin,s);
    Solution obj;
    string result = obj.reverseWords(s);
    cout<<"Output: "<<result;
    return 0;
}