#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0 , right =height.size()-1;
        int maxArea=0;
        while(left<right)
        {
            int area = min(height[left],height[right]) * (right-left);
            maxArea = max(area,maxArea);
            if(height[left]<height[right]) left ++;
            else right--;
        }
        return maxArea;
    }
};
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution obj;
    int ans = obj.maxArea(height);
    cout<<ans<<endl;
    
}