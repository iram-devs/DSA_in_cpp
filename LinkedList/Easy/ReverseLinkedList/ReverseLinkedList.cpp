#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *current = head;
        ListNode *next = NULL;

        while(current != NULL)
        {
            next = current->next;
            current->next=prev;
            prev = current;
            current = next;
        }
        return prev;
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
    ListNode* head = new ListNode(v[0]);
    ListNode* tail = head;
    for(int i =1;i<v.size();i++)
    {
        tail->next = new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}
int main()
{
 vector<int> v = {1,2,3,4,5};
 ListNode* list = createlist(v);
 Solution obj;
 ListNode* ans = obj.reverseList(list);
 printlist(ans);
 return 0;
}