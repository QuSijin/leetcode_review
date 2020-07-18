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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA; ListNode *t2 = headB;
        while(t1 != t2){//题目中两个链表长度不相同，所以以这种方式最终一定会相遇
            if (t1 == NULL)
                t1 = headA;
            else t1 = t1->next;
            if (t2 == NULL)
                t2 = headB;
            else t2 = t2->next;
        }
        return t1;

    }
};
