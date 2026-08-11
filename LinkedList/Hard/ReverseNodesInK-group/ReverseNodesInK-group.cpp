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
    ListNode* reversefirstK(ListNode* head , int k , ListNode**end , ListNode**nextHead)
    {
        int cnt =0;
        *end = head;
        ListNode* a ;
        ListNode* b = NULL;
        while(head != NULL && cnt<k)
        {
          a = head->next;
          head->next = b;
          b = head;
          head=a;
          cnt++;
        }
        *nextHead = a;
        if(cnt<k)
        {
            ListNode* prev = NULL;
            ListNode* curr = b;
            while(curr != NULL)
            {
                ListNode*temp = curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            *nextHead=NULL;
            return prev;
        }
        return b;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode*end , *nextHead;
        head = reversefirstK(head , k , &end , &nextHead);
        while(nextHead!=NULL)
        {
            ListNode* temp = end;
            temp->next = reversefirstK(nextHead , k , &end , &nextHead);
        }
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
    ListNode* list= createlist(v);
    Solution obj;
    ListNode* ans= obj.reverseKGroup(list , 2);
    printlist(ans);
    return 0;
}