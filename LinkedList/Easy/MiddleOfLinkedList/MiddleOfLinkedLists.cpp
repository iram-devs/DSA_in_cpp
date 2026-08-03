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
    ListNode* middleNode(ListNode* head) {
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        while(fastPtr != NULL && fastPtr->next != NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
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
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    ListNode* list = createlist(arr);
    Solution obj;
    ListNode* ans = obj.middleNode(list);
    cout<<ans->val<<endl;
    return 0;
}