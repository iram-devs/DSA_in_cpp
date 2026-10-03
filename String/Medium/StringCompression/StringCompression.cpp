#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int index=0;
        while(i<chars.size())
        {
            char current = chars[i];
            int count =0;
            while(i<chars.size()&& chars[i]==current)
            {
                count++;
                i++;
            }
            chars[index++]=current;
            if(count >1)
            {
                string cnt = to_string(count);
                for(char c: cnt)
                {
                    chars[index++]=c;
                }
            }
        }
       return index;
    }
};
int main()
{
    vector<char> chars;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter characters of array:\n";
    for(int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        chars.push_back(x);
    }

    Solution obj;
    int ans = obj.compress(chars);
    cout<<"Output: "<<ans<<endl;
    return 0;
}
