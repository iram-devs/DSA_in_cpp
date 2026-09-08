#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isDigit(char ch)
    {
        return (ch>='0' && ch<= '9');
    }
    int getNumber(string s , int &i)
    {
        int num = 0 ;
        while(i<s.size()&& isdigit(s[i]))
        {
            num = num*10 + (s[i]-'0');
            i++;
        }
        return num;
    }
    int compareVersion(string version1, string version2) {
        int i = 0 ,j=0;
        while(i< version1.size() || j<version2.size())
        {
            int num1 = 0;
            int num2 = 0;
            if(i<version1.size())
            {
                num1 = getNumber(version1,i);
            }
            if(j<version2.size())
            {
                num2 = getNumber(version2,j);
            }
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;

            //logic to skip
            if(i<version1.size()&&version1[i]=='.') i++;
            if(j<version2.size()&&version2[j]=='.') j++;
        }
        return 0;
    }
};
int main()
{
    string ver1 , ver2;
    cout<<"Enter Version string 1:\t";
    cin>>ver1;
    cout<<"Enter Version string 2:\t";
    cin>>ver2;

    Solution obj;
    int ans = obj.compareVersion(ver1 , ver2);
    cout<<"Output:\t"<<ans<<endl;
    return 0;
}