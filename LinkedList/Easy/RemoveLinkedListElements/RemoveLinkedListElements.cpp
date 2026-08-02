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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
        {
            ListNode *delNode = head;
            head = head->next;
            delete (delNode);
        }
        ListNode *temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            if(temp->next->val == val)
            {
                ListNode *delNode = temp->next;
                temp->next = temp->next->next;
                delete(delNode);
            }
            else
            {
                temp = temp->next;
            }
        }
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
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.removeElements(list , 6);
    printlist(ans);
    return 0;
}