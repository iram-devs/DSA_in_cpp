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
    ListNode* findNthNode(ListNode* temp , int k)
    {
        int cnt = 1;
        while (temp != NULL)
        {
           if(cnt == k) return temp;
           cnt++;
           temp = temp->next;  
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int n ;
        int count = 1;
        while( tail->next != NULL)
        {
           count++;
           tail= tail->next;
        }
        if(k % count == 0) return head;
        k = k % count;
        tail->next = head;
        ListNode* newlastnode = findNthNode(head , count - k);
        ListNode* newhead = newlastnode->next;
        newlastnode->next = NULL;
        return newhead;
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
    ListNode *head = new ListNode(v[0]);
    ListNode* tail = head;
    for(int i =1 ;i <v.size();i++)
    {
        tail->next= new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}
int main()
{
    vector<int> v = {1,2,3,4,5,6};
    ListNode* list = createlist(v);
    Solution obj;
    ListNode* ans = obj.rotateRight(list , 3);
    printlist(ans);
    return 0;
}