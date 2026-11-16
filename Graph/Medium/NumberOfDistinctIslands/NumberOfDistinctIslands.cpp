#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution{
    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, int row0, int col0, vector<pair<int,int>>&vec)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, 1};
        for(int i=0; i<4; i++)
        {
            int nr = row + delRow[i];
            int nc = col + delCol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1)
            {
                dfs(nr, nc, grid, vis, row0, col0,vec);
            }
        }
    }
    public:
    int distinctIslands(vector<vector<int>>&grid)
    {
        set<vector<pair<int,int>>>st;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,i,j,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
int main()
{
    vector<vector<int>>grid = {{1,1,0,1,1},
                               {1,0,0,0,0},
                               {0,0,0,1,1},
                               {1,1,0,0,1}};
    Solution obj;
    cout<<"No. of distinct islands: "<<obj.distinctIslands(grid);
    return 0;
}