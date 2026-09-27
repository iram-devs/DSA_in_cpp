#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26,0);
        for(char ch: words[0])
        {
           common[ch-'a']++;
        }
        for(int i=1 ;i<words.size();i++)
        {
            vector<int> freq(26,0);
            for(char ch: words[i])
            {
               freq[ch-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                common[i]=min(common[i],freq[i]);
            }
        }
        vector<string> ans;
        for(int i =0 ;i<26;i++)
        {
            while(common[i]>0)
            {
                ans.push_back(string(1,'a'+i));
                common[i]--;
            }
        }
        return ans;
    }
};
int main()
{
    vector<string> words={"cook","brook","hooked","crooked"};
    
    Solution obj;
    vector<string> ans = obj.commonChars(words);
    for(string s : ans)
    {
        cout<<s<<" ";
    }
    return 0;
}