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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smalldummy = new ListNode(0);
        ListNode* largedummy = new ListNode(0);
        ListNode* temp = head;
        ListNode* small = smalldummy;
        ListNode* large = largedummy;
        while(temp != NULL)
        {
            if(temp->val < x)
            {
                small->next = temp;
                small = small->next;
                temp=temp->next;
            }
            else
            {
                large->next = temp;
                large = large->next;
                temp=temp->next;
            }
        }
        small->next = largedummy->next;
        large->next = NULL;
        return smalldummy->next;
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
    vector<int> v = {1,2,3,6,4,5};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.partition(list,5);
    printlist(ans);
    return 0;
}