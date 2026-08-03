#include<iostream>
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
    bool hasCycle(ListNode *head) {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while (fastPtr != NULL && fastPtr->next !=NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(slowPtr == fastPtr)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third= new ListNode(3);
    ListNode* fourth= new ListNode(4);
    ListNode* fifth = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next=fifth;
    fifth->next = second;

    Solution obj;
    bool ans = obj.hasCycle(first);
    cout<<ans<<endl;
    return 0;

}