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
    ListNode* reverse(ListNode* head , ListNode* tail)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=tail)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        curr->next =prev;
        return curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start= head;
        ListNode* temp1 = NULL;
        int cnt = 1;
        while(cnt != left)
        {
            temp1=start;
            start= start->next;
            cnt++;
        }
        ListNode* end = start;
        while(cnt != right)
        {
          end = end->next;
          cnt++;
        }
        ListNode* temp2 = end ->next;
        ListNode* reversedhead = reverse(start,end);
       if(temp1 != NULL) temp1->next = reversedhead;
       else head= reversedhead;
       start->next = temp2;
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
    vector<int> v ={11 , 12 , 13 ,14 , 15, 16};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.reverseBetween(list  , 2 , 5);
    printlist(ans);
    return 0;
}