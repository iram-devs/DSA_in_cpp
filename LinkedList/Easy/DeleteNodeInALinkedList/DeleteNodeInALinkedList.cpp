#include<iostream>
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
    void deleteNode(ListNode* node) {
         ListNode* temp = node->next;
         node->val = temp->val;
         node->next= temp->next;
         delete temp;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next= new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    obj.deleteNode(head->next->next);
    printlist(head);
    return 0;
}