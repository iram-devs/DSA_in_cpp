#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void rev(string &s , int lo , int hi)
    {
        if(lo > hi) return;
        swap(s[lo],s[hi]);
        rev(s , lo + 1 , hi - 1);
    }
    void reverse(string &s)
    {
        int n = s.size();
        rev(s , 0 , n-1);
    }
};
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    Solution obj;
    obj.reverse(s);
    cout<<"Reversed String: "<<s;
    return 0;
}