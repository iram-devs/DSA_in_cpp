#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
      if((rec1[2]<=rec2[0])||(rec2[2]<=rec1[0])||(rec1[3]<=rec2[1])||(rec2[3]<=rec1[1]))
      {
        return false;
      }
      return true;  
    }
};
int main()
{
    vector<int>rec1 = {0,0,2,2};
    vector<int>rec2 = {1,1,3,3};

    Solution obj;
    bool ans = obj.isRectangleOverlap(rec1 , rec2);
    cout<<ans<<endl;
    return 0;
}