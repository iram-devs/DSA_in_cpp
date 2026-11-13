#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image, int newColor, int iniColor, int delRow[], int delCol[])
{
    ans[row][col]=newColor;
    int m = image.size();
    int n = image[0].size();
    for(int i=0; i<4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >=0 && nrow<m && ncol >=0 && ncol<n && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, iniColor, delRow, delCol);
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>>ans = image;
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0 , +1 , 0 , -1};
        dfs(sr,sc,ans,image,color, iniColor, delRow, delCol);
        return ans;
    }
};
int main()
{
    vector<vector<int>>image = {{1,1,0,1},
                                {2,1,1,2},
                                {0,1,1,2}};
   int sr = 2;
   int sc = 2;
   Solution obj;
   vector<vector<int>>ans = obj.floodFill(image, sr , sc , 3);
   cout<<"Output:"<<endl;
   for(int i=0;i<ans.size();i++)
   {
    for(int j = 0 ; j<ans[0].size();j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
}