#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0 , +1 , 0 , -1};
        int cnt=0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            cnt = max(cnt,t);
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]==1 && vis[nr][nc]!=2)
                {
                    q.push({{nr,nc},cnt+1});
                    vis[nr][nc]=2;
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2) return -1;
            }
        }
        return cnt;
    }
};
int main()
{
    vector<vector<int>>grid = {{1,1,2},
                               {1,1,0},
                               {2,1,0}};
    Solution obj;
    cout<<"Total time: "<<obj.orangesRotting(grid);
    return 0;
}