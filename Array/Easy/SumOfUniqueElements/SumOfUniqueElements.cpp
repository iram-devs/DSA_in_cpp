#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
      map<int,int>mp;
      int sum=0;
      for(int x:nums)
      {
        mp[x]++;
      }
      for(auto a :mp)
      {
        if(a.second==1) sum+=a.first;
      }
      return sum;
    }
};
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v;
    cout<<"Enter Array Elements:\n";
    for(int i = 0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution obj;
    cout<<"Sum: "<<obj.sumOfUnique(v);
    return 0;

}