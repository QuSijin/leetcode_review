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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        recur(root,sum);
        return ans;
    }
    void recur(TreeNode* root,int tar)
    {
        if(root==NULL) return ;
        path.push_back(root->val);
        tar-=root->val;//更新tar值
        if(tar==0&&root->left==NULL&&root->right==NULL)//找到符合的总和且一条路径已经走完
            ans.push_back(path);
            recur(root->left,tar);//左子树放进去
            recur(root->right,tar);//右子树放进去
            path.pop_back();//弹出path中的数，方便下一次递归
    }
};

