#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool helper(vector<vector<char>>&board, string word, int i, int j , int m , int n,int k)
    {
        if(k>=word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(word[k]!= board[i][j]) return false;
        board[i][j]='.';
        int x[4] = {0,0,-1,1};
        int y[4] = {-1,1,0,0};
        for(int index=0 ;index<4;index++)
        {
           if(helper(board , word , i+x[index],j+y[index],m,n,k+1))
           {
            board[i][j]=word[k];
            return true;
           }
        }
        board[i][j]=word[k];
        return false;;

    }
    bool exist(vector<vector<char>>& board, string word) {
       int rows = board.size();
       if(rows==0) return false;
       int col = board[0].size();
       if(word.size()==0)return false;
       for(int i=0;i<rows;i++)
       {
        for(int j =0 ;j<col;j++)
        {
            if(word[0]==board[i][j])
            {
                if(helper(board,word,i,j,rows,col,0)) return true;
            }
        }
       }
       return false;
    }
};
int main()
{
    vector<vector<char>> board={{'A','B','A','D'},{'R','T','E','V'},{'R','E','R','T'}};
    string word = "ADVERT";
    Solution obj;
    bool ans = obj.exist(board , word);
    cout<<ans<<endl;
    return 0;
}
