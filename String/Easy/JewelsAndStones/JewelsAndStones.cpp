#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char , bool> mp;
        int count=0;
        for(char ch : jewels)
        {
             mp[ch]=true;
        }
        for(char ch:stones)
        {
            if(mp[ch]==true) count++;
        }
        return count;
    }
};
int main()
{
    string jewels , stones;
    cout<<"Enter jewels: ";
    cin>>jewels;
    cout<<"Enter stones: ";
    cin>>stones;

    Solution obj;
    int ans = obj.numJewelsInStones(jewels,stones);
    cout<<"All the stones that are jewels are: "<<ans<<endl;
    return 0;
}