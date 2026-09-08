#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0 , j=0;
        string res="";
        while(i<word1.size() && j<word2.size())
        {
           res+=word1[i];
           res+=word2[j];
           i++;
           j++;
        }
        while(i<word1.size())
        {
            res+=word1[i];
            i++;
        }
        while(j<word2.size())
        {
            res+=word2[j];
            j++;
        }
        return res;
    }
};
int main()
{
    string w1 , w2;
    cout<<"Enter string 1:\t";
    cin>>w1;
    cout<<"Enter string 2:\t";
    cin>>w2;

    Solution obj;
    string ans = obj.mergeAlternately(w1 , w2);
    cout<<"Resultant Merged String:\t"<<ans<<endl;
    return 0;
}