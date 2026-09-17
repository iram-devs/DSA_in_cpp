#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        //if length of string is 1 return same string
        if(s.length()==1) return s;
        //if numRows is 1 return same string
        if(numRows == 1) return s;
        int idx = 0; //for traversing s
        int i=0;
        int j =0; //for imaginary 2D array
        vector<string> v(numRows , "");
        while(idx < s.length())
        {
            //downward motion
            while(idx<s.length() && i<numRows)
            {
                v[i].push_back(s[idx]);
                i++;
                idx++;
            }
            i-=2; //since i reaches at one step down of 2D array
            j++;  //moving one col ahad;

            //diagonal motion
            while(idx<s.length()&&i>=0)
            {
                v[i].push_back(s[idx]);
                i--;
                j++;
                idx++;
            }
            //after diagonal motion i reached -1 and j reaches one col ahead
            //bring at correct pos for downward motion 
            //bring i at row 1 as row 0 already filled and move j one step back
            i = 1 ;
            j--;
        }
        string result = "";
        for(int i = 0 ;i<numRows;i++)
        {
            result.append(v[i]);
        }
        return result;
    }
};
int main()
{
    int numRows;
    string s;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"Enter rows: ";
    cin>>numRows;

    Solution obj;
    string ans = obj.convert(s , numRows);
    cout<<"Result: "<<ans<<endl;
    return 0;

}