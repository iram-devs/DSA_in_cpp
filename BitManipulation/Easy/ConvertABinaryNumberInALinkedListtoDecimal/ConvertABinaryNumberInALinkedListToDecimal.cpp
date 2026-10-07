#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL)
        {
            ans=(ans<<1)|head->val;
            head=head->next;
        }
        return ans;
    }
};
int main()
{
    ListNode* head= new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    Solution obj;
    cout<<"Ans: "<<obj.getDecimalValue(head);
    return 0;
}