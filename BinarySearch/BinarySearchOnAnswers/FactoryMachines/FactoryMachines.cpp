/* Given a factory with N machines . i th machine takes T[i] seconds to produce one product.
   Each machine can continue producing products to any limit. Also Each machine can work simultaneously. 
   Find out the minimum time to produce K products.  */
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool canProduce(vector<int> &T , int time , int K)
    {
        int cnt =0;
        for(int i =0 ;i<T.size();i++)
        {
            cnt+= time/T[i];
        }
        if(cnt >= K) return true;
        else return false;
    }
    int minTimeToProduceProducts(vector<int>&T , int K)
    {
        //min time will always be time of the fastest machine
        int lo = *min_element(T.begin(),T.end());
        //max time will be the time of the fastest machine to produce k products alone
        int hi = lo*K ;
        int ans ;
        while(lo<=hi)
        {
            int mid = lo +(hi-lo)/2;
            if(canProduce(T , mid , K))
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        return ans;
    }
};
int main()
{
    vector <int> T = {2,3,7};
    int K = 10;
    Solution obj;
    int ans = obj.minTimeToProduceProducts(T , K);
    cout<<ans<<endl;
    return 0;
}