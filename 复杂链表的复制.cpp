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
