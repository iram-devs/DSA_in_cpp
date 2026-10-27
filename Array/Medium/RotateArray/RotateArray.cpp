#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
int main()
{
    int n ;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    Solution obj;
    obj.rotate(arr,k);
    cout<<"Output:"<<endl;
    for(int x : arr)
    {
        cout<<x<<" ";
    }
    return 0;
}