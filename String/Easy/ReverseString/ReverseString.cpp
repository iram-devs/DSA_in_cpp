#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
    public:
    void swap(char &a , char &b)
    {
        char temp = a;
        a=b;
        b=temp;
    }
    void reverseString(vector<char> &s)
    {
        int low = 0;
        int high = s.size()-1;
        while(low<=high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
};
int main()
{
    vector<char> str= {'h','e','l','l','o'};
    
    Solution obj;
    obj.reverseString(str);
    for(char x :str)
    {
        cout<<x<<" ";
    }
    return 0;
}