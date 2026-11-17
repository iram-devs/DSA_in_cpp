#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    bool check(int start, vector<int> adj[], vector<int>&vis, vector<int>&path)
    {
        vis[start]=1;
        path[start]=1;
        for(auto it: adj[start])
        {
            if(!vis[it])
            {
                if(check(it,adj,vis,path)==true)
                {
                    return true;
                }
            }
            else if(path[it])
            {
                return true;
            }
        }
        path[start]=0;
        return false;
    }
    public:
    bool hasCycle(int v, vector<int> adj[])
    {
        vector<int> vis{v,0};
        vector<int> pathVis{v,0};
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(check(i,adj,vis,pathVis)==true) return true;
            }
        }
        return false;
    }
};