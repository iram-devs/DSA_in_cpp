#include <iostream>
#include<vector>
#include <queue>
#include <list>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 struct Compare{
    bool operator()(ListNode* a , ListNode* b)
    {
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> ,Compare> pq;
        for(int i = 0 ;i<lists.size();i++)
        {
            if(lists[i] != NULL)
            {
                pq.push({lists[i]});
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy ;
        while(!pq.empty())
        {
            ListNode* p = pq.top();
            pq.pop();
            temp->next = p;
            temp = temp->next;
            if(p->next != NULL)
            {
                pq.push({p->next});
            } 
        }
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
    vector<int> v1 = {1,4,6};
    vector<int> v2 = {2,4,5,7};
    vector<int> v3 = {3,6,8};
    vector<int> v4 = {8,9};
    ListNode* list1 = createlist(v1);
    ListNode* list2 = createlist(v2);
    ListNode* list3 = createlist(v3);
    ListNode* list4 = createlist(v4);
    vector <ListNode*> lists = {list1 , list2 , list3 , list4};
    Solution obj;
    ListNode* ans = obj.mergeKLists(lists);
    printlist(ans);
    return 0;
}