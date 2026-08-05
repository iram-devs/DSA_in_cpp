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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
         ListNode* odd = head;
         ListNode* even = head->next;
         ListNode* evenHead = head->next;
         while(even != NULL && even->next != NULL)
         {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
         }
         odd->next = evenHead;
         return head;
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
    vector<int> v = {1,2,3,4,5,6,7};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.oddEvenList(list);
    printlist(ans);
    return 0;
}