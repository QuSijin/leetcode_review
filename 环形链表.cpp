/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
bool hasCycle(ListNode* head) 
{
	
	if(head==NULL) return false;
    ListNode* h = head;//快的
    ListNode* l = head;//慢的
    while(h!=NULL && h->next!=NULL)//用快的那个做判断条件
    {
        h=h->next->next;
        l=l->next;
        if(l==h)
        {
            return true;
        }
    } 
    return false;
}
};
