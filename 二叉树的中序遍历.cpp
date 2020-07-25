class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur||st.size())
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            cur=cur->right;
        }
        return ans;
    }
};
