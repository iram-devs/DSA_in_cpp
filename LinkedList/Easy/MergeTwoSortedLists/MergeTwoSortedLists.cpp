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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 ==  NULL) return list1;
         ListNode* dummy = new ListNode(-1);
         ListNode* t1 = list1;
         ListNode* t2 = list2;
         ListNode* temp = dummy;
         while(t1 != NULL && t2 != NULL)
         {
            if(t1->val <= t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
         }
         if(t1) temp->next = t1;
         else temp->next = t2;
        
        return dummy->next;
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1 , list2);
    printlist (ans);
    return 0;
    
}