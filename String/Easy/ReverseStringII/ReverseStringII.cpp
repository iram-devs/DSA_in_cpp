#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i =0 ; i<s.size();i+=2*k)
        {
            int low = i;
            int high = min((i+k-1), (int)s.size()-1);
            while(low<=high)
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};
int main()
{
    string s = "abcdefg";
    int k =2;

    Solution obj;
    string ans = obj.reverseStr(s,k);
    for(char x: ans)

    {
        cout<<x;
    }
    return 0;

}