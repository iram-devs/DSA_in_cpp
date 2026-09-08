#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    string Profession(int level , int pos)
    {
        //base case
        if(level == 1) return "Engineer";

        //recursive code to find parent of node at given pos and level
        string parent = Profession(level-1 , (pos+1)/2);

        if(pos%2 == 1)
        {
            return parent;
        }
        else if (parent == "Doctor") return "Engineer";
        else return "Doctor";
    }
};
int main()
{
    int level , pos;
    cout<<"Enter level:\t"<<endl;
    cin>>level;
    cout<<"Enter position:\t"<<endl;
    cin>>pos;
    
    Solution obj;
    string ans = obj.Profession(level , pos);
    cout<<"Profession : "<<ans<<endl;
    return 0;

}