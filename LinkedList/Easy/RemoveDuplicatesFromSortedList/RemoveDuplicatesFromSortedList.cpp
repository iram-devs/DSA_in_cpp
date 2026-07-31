#include <iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {
                ListNode *delNode = temp->next;
                temp->next = temp->next->next;
                delete(delNode);
            }
           else
           {
            temp = temp->next;
           }
        }
        return head;
    }
};
void printlist(ListNode *head)
{
     ListNode* temp = head;
     while(temp)
     {
        cout<<temp->val<<" ";
        temp = temp->next;
     }
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next ->next= new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    Solution obj;
    ListNode* ans = obj.deleteDuplicates(head);
    printlist(ans);
    return 0;

}