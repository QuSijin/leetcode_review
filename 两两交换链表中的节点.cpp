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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* nextt=head->next;
        //若题为1->2->3->4
      
       head->next = swapPairs(nextt->next);//1->3
       nextt->next = head;//2->1
        //第一层递归后即为2->1->3->4
        return nextt;

        

    }
};

