#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool check(string &s , int low , int high)
    {
        while(low<high)
        {
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int low = 0 , high = s.size()-1;
        int cnt=1;
        while(low<=high)
        {
            if(s[low]!=s[high])
            {
                return check(s , low+1 , high) || check(s , low , high-1);
            }
            low++;
            high--;
        }
        return true;
    }
};
int main()
{
    string s1 = "abcca";
    string s2 = "abcda";

    Solution obj;
    cout<<obj.validPalindrome(s1); //true
    cout<<endl;
    cout<<obj.validPalindrome(s2); //false
    return 0;
}