#include <iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int maxProfit=0;
         int minPrice=INT_MAX;
         for(int i=0;i<prices.size();i++)
         {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
         }
         return maxProfit;
        
    }
};
int main()
{
    vector <int> prices = {7,1,5,3,6,4};
    Solution obj;
    int ans = obj.maxProfit(prices);
    cout<<ans<<endl;
    return 0;
}