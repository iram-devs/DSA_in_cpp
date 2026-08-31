#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Given : Array named stalls representing positions where cow can be placed and integer k representing no. of cows to be placed
//Find Minimum distance at which cows can be placed which is also the maximum possible distance.
bool CanCowBePlaced(vector<int> &stalls , int dist , int k)
{
    int cows =1;
    int pos =0;
    for(int i = 1;i<stalls.size();i++)
    {
        if(stalls[i]-stalls[pos]>=dist) 
        {
            cows++;
            pos = i;
        }
    }
    if(cows >= k) return true;
    else return false;
}

int AgressiveCows(vector<int>stalls , int k)
{
    sort(stalls.begin(),stalls.end());
    int low = 1 , high = stalls[stalls.size()-1] - stalls[0];
    int ans=0 ;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if (CanCowBePlaced(stalls , mid , k))
        {
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
} 
int main()
{
    vector<int> stalls = {1 , 2, 4 ,8,9};
    int k =3;
    int ans = AgressiveCows(stalls , k);
    cout<<ans<<endl;
    return 0;
}