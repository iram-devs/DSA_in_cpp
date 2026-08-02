#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    vector<int> ans = {};
    int n = digits.size()-1;
    int sum =digits[n]+1;
    int carry = sum/10;
    ans.push_back(sum%10);
    int i = n-1;
    while(i>=0)
    {
        if(carry)
        {
            int digit = (digits[i]+carry);
            carry = (digits[i]+carry)/10;
            ans.push_back(digit%10);
            i--;
        }
        else
        {
            ans.push_back(digits[i]);
            i--;
        }
    }
    if(carry>0) ans.push_back(carry);
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
int main()
{
    vector<int> digits = {9,9,9};
    Solution obj;
    vector <int> ans = obj.plusOne(digits);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}