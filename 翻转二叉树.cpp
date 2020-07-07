class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;

    }
};
