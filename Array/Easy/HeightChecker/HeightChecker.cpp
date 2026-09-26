#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(),temp.end());
        int count=0;
        for(int i =0;i<heights.size();i++)
        {
            if(heights[i]!=temp[i]) count++;
        }
        return count;
    }
};
int main()
{
    vector<int>heights = {1,2,4,3,2,3};
    Solution obj;
    int ans = obj.heightChecker(heights);
    cout<<ans<<endl;
    return 0;
}