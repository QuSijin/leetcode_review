/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre, *head;
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        dfs(root);
        head->left=pre;//进行头节点和尾节点的相互指向，这两句的顺序也是可以颠倒的
        pre->right=head;
        return head;
    }

    void dfs(Node* cur){
        if(cur==NULL) return;
        dfs(cur->left);//先递归左子树，因为数值小
        //pre用于记录双向链表中位于cur左侧的节点，即上一次迭代中的cur
        //pre!=null时，cur左侧存在节点pre，需要进行pre.right=cur的操作。
        if(pre!=NULL) pre->right=cur;
        
        //当pre==null时，cur左侧没有节点,即此时cur为双向链表中的头节点
        else head=cur;

        cur->left=pre;//pre是否为null对这句没有影响,且这句放在上面两句if else之前也是可以的。
        pre=cur; //pre指向当前的cur
        dfs(cur->right);//递归右子树
    }
};
