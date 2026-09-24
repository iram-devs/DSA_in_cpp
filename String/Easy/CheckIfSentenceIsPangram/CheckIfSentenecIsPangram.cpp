#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> presence(26,false);
        for(char ch: sentence)
        {
            presence[ch-'a']=true;
        }
        for(bool b: presence)
        {
            if(b==false)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string sentence;
    cout<<"Enter the sentence: ";
    cin>>sentence;
    Solution obj;
    cout<<"Output: "<<obj.checkIfPangram(sentence);
    return 0;
}