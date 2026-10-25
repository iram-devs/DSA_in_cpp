#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int i = 0; i<asteroids.size();i++)
        {
            if(asteroids[i]>0) ans.push_back(asteroids[i]);
            else
            {
                while(ans.size()!=0 && ans.back()>0 && ans.back()<abs(asteroids[i]))
                {
                    ans.pop_back();
                }
                if(ans.size()!=0 && ans.back()==abs(asteroids[i]))
                {
                    ans.pop_back();
                }
                else if(ans.size()==0 || ans.back()<0) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int>asteroids;
    int n;
    cout<<"enter no. of asteroids: ";
    cin>>n;
    cout<<"enter asteroids in order:"<<endl;
    for(int i= 0 ;i<n ;i++)
    {
        int x;
        cin>>x;
        asteroids.push_back(x);
    }
    Solution obj;
    vector<int>res = obj.asteroidCollision(asteroids);
    cout<<"asteroids after collision:"<<endl;
    for(int x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}