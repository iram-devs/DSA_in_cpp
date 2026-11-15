#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[r][c]=step;
            for(int i=0;i<4;i++)
            {
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0)
                {
                    q.push({{nr,nc},step+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return dist;
    }
};