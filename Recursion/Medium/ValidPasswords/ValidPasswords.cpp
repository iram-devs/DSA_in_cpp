#include<iostream>
#include <string>
#include<vector>
using namespace std;
class Solution{
    public:
    int totalPasswords(int n , string res , char prev , vector<char> &arr)
    {
        //base case
        if(res.size()==n) return 1;
        int ways=0;
        for(int i = 0; i< arr.size() ; i++)
        {
            if(arr[i]=='B' && prev == 'A') continue;
            else if(arr[i]=='B' && prev == 'B') continue;
            else if(res.size()>= 2 && res[res.size()-1]=='C' && res[res.size()-2]=='C'&& arr[i]=='C')
            {
              continue;
            }
            else
            {
             ways += totalPasswords(n , res + arr[i], arr[i] , arr);
            }
        }
        return ways;  
    }
};
int main()
{
    vector<char> arr = {'A','B','C'};
    string res = "";
    char prev = '#';
    int n ;
    cout<<"Enter length of password"<<endl;
    cin>>n;

    Solution obj;
    int ans = obj.totalPasswords(n , res , prev , arr);
    cout<<"Total passwords valid :\t"<< ans<<endl;
    return 0;

}