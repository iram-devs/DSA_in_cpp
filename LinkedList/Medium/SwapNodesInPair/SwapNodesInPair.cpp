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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(prev->next && prev->next->next)
        {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            prev->next=second;

            prev = first;
        }
        return dummy->next;
    }
};
int main()
{
    ListNode* head = new ListNode(8);
    head->next = new ListNode(9);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(11);
    head->next->next->next->next = new ListNode(12);

    Solution obj;
    ListNode* ans = obj.swapPairs(head);
    cout<<"Output: "<<endl;
    ListNode* temp = ans;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return 0;
}