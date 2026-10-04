#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x , ListNode* next): val(x),next(next){}
};
class Solution{
    public:
    ListNode* sum(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1!=NULL || t2!=NULL)
        {
            int sum = carry;
            if(t1) sum+=t1->val;
            if(t1) sum+=t2->val;
            ListNode* newnode= new ListNode(sum%10);
            carry = sum/10;
            curr->next = newnode;
            curr=curr->next;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        if(carry)
        {
            ListNode* newnode = new ListNode(carry);
            curr->next = newnode;
        }
        return dummy->next;

    }
};
ListNode* createList(vector<int>&v)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for(int i=0;i<v.size();i++)
    {
        ListNode* newnode = new ListNode(v[i]);
        curr->next = newnode;
        curr=curr->next;
    }
    return dummy->next;
}
void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main()
{
    vector<int> v1 = {4,3,6,5};
    vector<int> v2 = {5,3,4,2};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    Solution obj;
    ListNode* ans = obj.sum(l1,l2);
    cout<<"Output: "<<endl;
    printList(ans);
    return 0;

}