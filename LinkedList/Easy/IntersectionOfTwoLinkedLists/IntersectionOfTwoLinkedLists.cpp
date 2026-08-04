#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2)
        {
            p1 = (p1==NULL)?headB :p1->next;
            p2 = (p2==NULL)?headA :p2->next;
        }
        return p1;
    }
};
int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(6);
    list2->next = new ListNode(7);
    list2->next = new ListNode(8);
    list2->next->next = list1->next->next;

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(list1 , list2);

    cout<<ans->val<<endl;
    return 0;


}