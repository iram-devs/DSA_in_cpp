#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int stringToInteger(string s)
    {
        int i=0;
        int ans =0;
        while(i<s.size())
        {
            int digit = s[i]-'0';
            ans = ans*10 + digit;
            i++;
        }    
        return ans;
    }
    /*string IntegerToString(int num)
    {
        string str="";
        while(num>0)
        {
            int digit = num%10;
            char ch = digit + '0';
            str = ch + str;
            num = num/10;
        }
        return str;
    }*/
    string multiply(string num1, string num2) {
        int n1 = stringToInteger(num1);
        int n2 = stringToInteger(num2);
        int product = n1*n2;
        //return IntegerToString(product);
        return to_string(product);
    }
};