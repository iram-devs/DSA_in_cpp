#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*To find out min no. of bananas per hr required by koko to eat to finish
 the bananas given in piles before or in 'h' hours*/
class Solution{
    public:
    bool CanBeFinished(vector<int>&piles , int k , int h)//k-minspeed of koko , h=maxtime
   {
     int hrs = 0;
     for(int i =0 ;i<piles.size();i++)
    {
      hrs+=(piles[i]+k-1) / k;
    }
    return(hrs <= h);
   } 
   int MinimumBananas(vector<int>&piles , int h)
   {
     sort(piles.begin(),piles.end());
     int n = piles.size();
     int low = 1;
     int high = piles[n-1];
     int ans=high;
     while(low<=high)
     {
        int mid = low + (high-low)/2;
        if(CanBeFinished(piles , mid , h)==true)
        {
            ans = mid;
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
     }
     return ans;
   }
};
int main()
{
  vector<int> piles = {3,6,7,9,11};
  int h = 8;

  Solution obj;
  int ans = obj.MinimumBananas(piles , h);
  cout<<ans<<endl;
  return 0;
}