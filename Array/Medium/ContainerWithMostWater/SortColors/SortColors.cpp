#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void selectionsort(vector<int> &v)
    {
        int n = v.size();
        for(int i =0 ; i<n-1;i++)
        {
            int minidx = i;
            for(int j =i+1 ; j<n;j++)
            {
                if(v[j]<v[minidx])
                {
                    minidx = j;
                }
            }
            swap(v[i],v[minidx]);
        }
    }
    void sortColors(vector<int>& nums) {
        selectionsort(nums);
        
    }
};
int main()
{
    vector<int> v = {2,1,0,1,1,2,0};
    Solution obj;
    obj.sortColors(v);
    for(int x : v)
    {
        cout<<x<<" ";
    }
    return 0;
}