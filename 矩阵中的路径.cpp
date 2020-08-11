class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k])//1. 行或列索引越界 或 2.当前矩阵元素与目标字符不同 或3.当前矩阵元素已访问过 （3 可合并至 2 ） 。
            return false;
        if (k == word.length() - 1)//字符串 word 已全部匹配，即 k = len(word) - 1 。
            return true;
        char temp = board[i][j];
        board[i][j] = '/';//标记当前矩阵元素： 将 board[i][j] 值暂存于变量 tmp ，并修改为字符 '/' ，代表此元素已访问过，防止之后搜索时重复访问。
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
                      dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);//搜索下一单元格： 朝当前元素的 上、下、左、右 四个方向开启下层递归，使用 或 连接 （代表只需一条可行路径） ，并记录结果至 res 。
        board[i][j] = temp;//还原当前矩阵元素： 将 tmp 暂存值还原至 board[i][j] 元素。
        return res;
    }
};

