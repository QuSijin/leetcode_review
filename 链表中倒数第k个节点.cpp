//第一次复习
//经典快慢指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* low = head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(k==0)
            {
                low=low->next;
            }else{
                k--;//k减到0时low开始出发，即low一直和fast差k步
            }
            
        }
        return low;
    }
};

//第二次复习
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* low = head;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(k==0)
            {
                low = low->next;
            }else{
                k--;
            }
        }     
        return low;
    }
};
