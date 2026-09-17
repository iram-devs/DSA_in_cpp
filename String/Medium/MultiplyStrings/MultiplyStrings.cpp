#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n+m , 0);
        for(int i=n-1 ; i>=0;i--)
        {
            for(int j = m-1 ;j>=0 ;j--)
            {
                int dig1 = num1[i]-'0';
                int dig2 = num2[j]-'0';
                int product = dig1 * dig2;
                int sum = product + ans[i+j+1];
                ans[i+j+1] = sum%10;
                ans[i+j]+=sum/10;
            }
        }
        string result = "";
        for(int x:ans)
        {
            if(result.empty() && x==0 ) continue;
            result+= char(x+'0');
        }
        return result;
    }
};
int main()
{
    string num1 , num2;
    cout<<"Enter string1: ";
    cin>>num1;
    cout<<"Enter string2: ";
    cin>>num2;

    Solution obj;
    string ans = obj.multiply(num1 , num2);
    cout<<"Output: "<<ans<<endl;
    return 0;
}