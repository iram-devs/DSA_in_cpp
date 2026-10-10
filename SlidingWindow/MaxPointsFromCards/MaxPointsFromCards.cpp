#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = INT_MIN;
        int sum = 0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        ans = max(ans,sum);
        for(int i=0;i<k;i++)
        {
           sum -= cardPoints[k-1-i];
           sum += cardPoints[n-1-i];
           ans = max(ans,sum);
        }
        return ans;
    }
};