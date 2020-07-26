/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return NULL;
        int left_h = maxDepth(root->left);//遍历左
        int right_h = maxDepth(root->right);//遍历右
        return  max(left_h,right_h)+1;//左右的最大深度加一即为树的深度
       
    }
};
