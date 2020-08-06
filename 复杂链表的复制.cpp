class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*>mp;//map中存的是(原节点，拷贝节点)的一个映射
       Node* t = head;
       while(t!=NULL)
       {
           mp[t]=new Node(t->val);//放入hash
           t=t->next;
       }
       t=head;
       while(t!=NULL)
       {
           if(t->next)
           {
               mp[t]->next = mp[t->next];//next复制对应关系
           }
           if(t->random)
           {
               mp[t]->random = mp[t->random];//random复制对应关系
           }
           t = t->next;
       }
       return mp[head];
    }
};
//2.原地修改链表
///*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 完成链表节点的复制
        Node* cur = head;
        while(cur != nullptr){
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;//下一个变成当前节点
        }
       // 完成链表复制节点的随机指针复制
        cur = head;
        while(cur != nullptr){
            if(cur->random != nullptr)// 注意判断原来的节点有没有random指针
                cur->next->random = cur->random->next;//若1random->3,1'random->3'
            cur = cur->next->next;
        }
         // 将链表一分为二
       Node* copyHead = head->next;
        cur = head;
        Node* curCopy = head->next;
        while (cur != nullptr) {
            cur->next = cur->next->next;
            cur = cur->next;
            if (curCopy->next != nullptr) {
                curCopy->next = curCopy->next->next;
                curCopy = curCopy->next;
            }
        }
        return copyHead;
    }
};
