#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        if(x==1)return 1;
      int i=0;
      int j=x;
      int ans=1;
      while(i<=j){
      int mid=(i+j)/2;
      if(mid<=(x/mid))
      {
        ans=mid;
        i=mid+1;
      }
      else{
       j=mid-1;
      }
    }
    return ans;      
       
    }
};
int main()
{
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    Solution obj;
    int ans = obj.mySqrt(x);
    cout<<"Answer: "<<ans<<endl;
    return 0;
}