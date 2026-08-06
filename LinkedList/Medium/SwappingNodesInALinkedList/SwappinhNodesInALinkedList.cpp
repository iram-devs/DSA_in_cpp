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
    int countnodes(ListNode* head)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstnode = head;
        for(int i = 1 ; i<k ;i++)
        {
          firstnode = firstnode->next;
        }
        int n = countnodes(head);
        ListNode* lastnode = head;
        for(int i =1 ; i < n - k + 1 ;i++)
        {
           lastnode = lastnode->next;
        }
        swap(firstnode->val , lastnode->val);
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
    vector<int> v ={1,2,3,4,5,6,7};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.swapNodes(list , 2);
    printlist(ans);
    return 0;
}