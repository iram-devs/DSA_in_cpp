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
    ListNode* mid(ListNode*head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast= fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!= NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
      ListNode* last = head;
      while(last->next != NULL)
      {
        last = last->next;
      }
      ListNode* firsthead=head;
      ListNode* middle = mid(head);
      ListNode* secondhead = reverse(middle->next);
      middle->next = NULL;
      ListNode* temp = head;
      while( secondhead != NULL)
      {
        ListNode* temp1 = firsthead->next;
        ListNode* temp2 = secondhead->next;
        firsthead->next = secondhead;
        secondhead->next = temp1;
        firsthead = temp1;
        secondhead = temp2;
      }
    }
};
ListNode* createlist(vector<int> v)
{
    ListNode* head = new ListNode(v[0]);
    ListNode* tail = head;
    for(int i =1;i<v.size();i++)
    {
        tail->next = new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}
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
    vector<int> v1 = {1,2,3,4,5};
    ListNode* list1 = createlist(v1);
    Solution obj1;
    obj1.reorderList(list1);
    printlist(list1);

    cout<<endl;

    vector<int>v2 = {1,2,3,4};
    ListNode* list2 = createlist(v2);
    Solution obj2;
    obj2.reorderList(list2);
    printlist(list2);
    return 0;
 }