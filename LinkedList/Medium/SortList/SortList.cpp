#include <iostream>
#include <queue>
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
    ListNode* sortList(ListNode* head) {
        priority_queue<pair<int , ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int , ListNode*>>> pq;
        ListNode* temp = head;
        while(temp!=NULL) 
        {
            pq.push({temp->val,temp});
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp2=  dummy;
        while(!pq.empty())
        {
            ListNode* curr = pq.top().second;
            pq.pop();
            temp2->next = curr;
            temp2 = temp2->next; 
        }
        temp2->next = NULL;
        return dummy->next;
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
    vector<int> v ={2,4,1,5,3};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.sortList(list);
    printlist(ans);
    return 0;
 }