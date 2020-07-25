1.2.
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        } 
        ListNode* curr = reverseList(head->next);//找到队尾
       
        head->next->next = head;//head的下一个结点指向head
        head->next = NULL;//头指向空
        return curr;
    }
};
