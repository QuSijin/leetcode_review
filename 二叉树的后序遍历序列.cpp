//1.递归分治
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
    bool recur(vector<int> postorder, int i, int j) {
        if(i >= j) return true;//节点数<=1,无需判定
        int p = i;//从头开始
        while(postorder[p] < postorder[j]) p++;//找第一个大于根的节点
        int m = p;//m为第一个大于根的节点
        while(postorder[p] > postorder[j]) p++;//遍历右子树区间，看是否都大于根节点
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);//一直到p==j且左右子树都成立即可确定
    }

};
//2.辅助单调栈
//还不太看得懂，下次吧~
