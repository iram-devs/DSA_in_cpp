#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int findCelebrity(vector<vector<int>>&matrix)
    {
        int n = matrix.size();
        int top=0;
        int down=n-1;
        while(top<down)
        {
            if(matrix[top][down]==1)
            {
                top++;
            }
            else if(matrix[down][top]==1)
            {
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        for(int i = 0 ;i<n-1;i++)
        {
            if(i==top)continue;
            if(matrix[top][i]==0 && matrix[i][top]==1){}
            else return -1;
        }
        return top;
    }
};
int main()
{
    vector<vector<int>>matrix={{0,1,1,0},
                               {0,0,0,0},
                               {0,1,0,0},
                               {1,1,0,0}};
    Solution obj;
    cout<<"celebrity="<<obj.findCelebrity(matrix);
    return 0;
}