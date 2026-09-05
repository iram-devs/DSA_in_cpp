#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' ||c=='e'|| c=='i'||c== 'o'||c=='u' || c=='A'||c=='E'||c=='I'|| c=='O'||c=='U');
    }
    string reverseVowels(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low<=high)
        {
            if(isVowel(s[low]) && isVowel(s[high]))
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(!isVowel(s[low])) low++;
            else high--;
        }
        return s;
    }
};
int main()
{
    string s = "IceCream";
    Solution obj;
    string ans = obj.reverseVowels(s);
    cout<<ans<<endl;
    return 0;
}