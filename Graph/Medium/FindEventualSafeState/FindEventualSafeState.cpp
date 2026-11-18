#include<iostream>
#include<vector>
using namespace std;
class Solution {
 private:
 bool dfs(int start, vector<vector<int>>&graph, vector<int>&vis, vector<int>&pathVis, vector<int>&check)
 {
    vis[start]=1;
    pathVis[start]=1;
    check[start]=0;
    for(auto it:graph[start])
    {
        if(!vis[it])
        {
            if(dfs(it,graph,vis,pathVis,check))
          {
            check[start]=0;
            return true;
            break;
          }
        }
        else if(pathVis[it]==1)
        {
            check[start]=0;
            return true;
            break;
        }
    }
    check[start]=1;
    pathVis[start]=0;
    return false;
 }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);
        vector<int>check(v,0);
        vector<int>ans;
        for(int i=0;i<v;i++)
        {
            if(!vis[i]) dfs(i,graph,vis,pathVis,check);
        }
        for(int i=0;i<v;i++)
        {
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};