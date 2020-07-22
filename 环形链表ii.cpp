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
    ListNode *detectCycle(ListNode *head) {
        
       ListNode* fast = head;
       ListNode* slow = head;
       while(true){
           if(fast==NULL || fast->next==NULL) return NULL;
           fast = fast->next->next;
           slow = slow->next;
           if(slow == fast) break;
       }
       fast = head;
       while(slow!=fast)
       {
           slow = slow->next;
           fast = fast->next;
       }
       return fast;
    }
};


