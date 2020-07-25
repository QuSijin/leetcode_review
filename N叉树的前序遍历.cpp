//解法和中序遍历很像，中序遍历放右子树，N叉树前序遍历放孩子子树
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)   return res;
        stack<Node*> stk;
        stk.push(root);
        while(stk.size()){
            Node* cur = stk.top(); 
            res.push_back(cur -> val);//u 
            stk.pop();//1.u出 2.v1、v2、v3出
            for(int i = cur -> children.size()-1; i >= 0; --i){
                stk.push(cur -> children[i]);//v3、v2、v1
            }
        }
        return res;//u、v1、v2、v3
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
