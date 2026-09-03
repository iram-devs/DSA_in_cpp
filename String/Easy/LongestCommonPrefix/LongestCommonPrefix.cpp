#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    string longestCommonPrefix(vector<string>&str)
    {
        sort(str.begin(),str.end());
        int n = str.size();
        string first = str[0];
        string last = str[n-1];
        string res;
        int i =0;
        while(i<first.size()&&i<last.size() && first[i]==last[i])
        {
            res+=first[i];
            i++;
        }
        return res;
    }
};
int main()
{
    vector<string> str = {"Flower","Flow","Florist","Flowing"};
    Solution obj;
    string ans = obj.longestCommonPrefix(str);
    cout<<ans<<endl;
    return 0;
}