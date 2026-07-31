#include <iostream>
#include <vector>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for(int i =0 ; i<n;i++)
        {
            fast = fast->next;
        }
        if(fast == NULL)
        {
            ListNode *newhead = head->next;
            delete(head);
            return newhead;
        }
        ListNode *slow = head;
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
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
ListNode* createlist(vector<int> v)
{
    ListNode *head = new ListNode(v[0]);
    ListNode* tail = head;
    for(int i =1 ;i <v.size();i++)
    {
        tail->next= new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}
int main()
{
   vector <int> arr = {2,3,1,5,4,6,7,9,0,8};
   ListNode* list = createlist(arr);

   Solution obj;
   ListNode* ans = obj.removeNthFromEnd(list , 3);
   printlist(ans);
   return 0;
}