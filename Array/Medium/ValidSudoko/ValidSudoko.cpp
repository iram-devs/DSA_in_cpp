#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);
        int n = board.size();
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                int cell=board[r][c];
                if(cell=='.') continue;
                if(row[r].count(cell)) return false;
                row[r].insert(cell);
                if(col[c].count(cell)) return false;
                col[c].insert(cell);
                int box_no= 3*(r/3) + (c/3);
                if(box[box_no].count(cell)) return false;
                box[box_no].insert(cell);
            }
        }
     return true;
    }
};
int main()
{
    vector<vector<char>>board = {{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    Solution obj;
    bool ans = obj.isValidSudoku(board);
    cout<<ans<<endl;
    return 0;
}


