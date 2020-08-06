//前序和中序重建二叉树
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
    
    unordered_map<int,int> mp;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTreeUtil(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
 
    TreeNode* buildTreeUtil(vector<int>& preorder, int p_start,int p_end,
    vector<int>& inorder, int i_start, int i_end) {
        
        if(p_start == p_end)
        {
            return NULL;
        }
        int root_val = preorder[p_start];//找到根节点--前序的起始位置
        TreeNode* root = new TreeNode(root_val);
        int i_root_index = mp[root->val];//找到根节点的下标
        
        int leftNum = i_root_index - i_start;//左子树的个数
       
        //递归左子树
        root->left = buildTreeUtil(preorder, p_start + 1, p_start + leftNum + 1, inorder, i_start, i_root_index);
        //[p_start + 1~p_start + leftNum + 1]为前序左子树范围
        //[i_start~i_root_index]为中序左子树范围

        //递归右子树
        root->right = buildTreeUtil(preorder, p_start + leftNum + 1, p_end, inorder, i_root_index + 1, i_end);
        //[p_start + leftNum + 1~p_end]为前序右子树范围
        //[i_root_index + 1~i_end]为中序右子树范围
    return root;
    }

};
