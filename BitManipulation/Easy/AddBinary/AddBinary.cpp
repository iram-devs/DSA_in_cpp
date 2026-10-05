#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry)
        {
            int sum = carry;
            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';

            ans.push_back('0'+sum%2);
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    string a ,b;
    cout<<"Enter a in binary form: ";
    cin>>a;
    cout<<"Enter b in binary form: ";
    cin>>b;
    Solution obj;
    cout<<"Output: "<<obj.addBinary(a,b);
    return 0;
}