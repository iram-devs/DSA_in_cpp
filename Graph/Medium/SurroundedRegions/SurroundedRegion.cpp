#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>&board, vector<vector<int>>&vis)
    {
        int m = board.size();
        int n = board[0].size();
        vis[row][col]=1;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
           int nr = row + delRow[i];
           int nc = col + delCol[i];
           if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O')
           {
            dfs(nr,nc,board,vis);
           }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        //boundaru Os
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(board[i][j]=='O' && !vis[i][j]) dfs(i,j,board,vis);
                }
            }
        }
        //checking unvisited Os
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(board[i][j]=='O' && !vis[i][j])
                    {
                        board[i][j]='X';
                    }
                }
            }
        }
    }
};
int main()
{
    vector<vector<char>> board = {{'X','X','X','X','X'},
                                  {'X','X','X','O','X'},
                                  {'O','X','X','O','X'},
                                  {'O','O','X','X','O'},
                                  {'X','O','X','X','X'}};
    Solution obj;
    obj.solve(board);
    cout<<"Output matrix:"<<endl;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}