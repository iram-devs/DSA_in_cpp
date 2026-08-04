#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        vector <int> v;
        while(head !=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }

        int left=0,right=v.size()-1;
        while(left<right)
        {
            if(v[left]!=v[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
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
    vector<int> v = {1,2,3,4,3,2,1};
    ListNode* list = createlist(v);
    Solution obj;
    bool ans = obj.isPalindrome(list);
    cout<<ans<<endl;
    return 0;
}