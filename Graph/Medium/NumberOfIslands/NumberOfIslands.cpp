#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void bfs(int row , int col , vector<vector<bool>> &vis , vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=true;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int d = 0 ; d<4 ;d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr >= 0 && nr <m && nc >=0 && nc < n && grid[nr][nc]=='1' && !vis[nr][nc])
                {
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col]=='1' && !vis[row][col])
                {
                    bfs(row , col , vis , grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};