//1.
class Solution {
public:
    vector<double> twoSum(int n) {
        //n <= 11
        vector<vector<double>>dp(n + 1, vector<double>(6*n + 1, 0));//n+1和6*n+1是为了不要0，从1开始
        vector<double> ans;
        for(int i = 1; i <= n; i ++){//n个骰子
            for(int j = i; j <= 6*i; j ++){//总点数
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int k = 1; k <= 6; k ++){//每个骰子的点数
                    if(j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for(int i = n; i <= 6*n; i ++){
            ans.push_back(dp[n][i] * pow(1.0/6, n));//转换为概率
        }
        return ans;
    }
};
//2.
class Solution {
public:
    vector<double> twoSum(int n) {
        //n <= 11
        vector<vector<double>>dp(n + 1, vector<double>(6*n + 1, 0));//n+1和6*n+1是为了不要0，从1开始
        vector<double> ans;
        for(int i = 1; i <= n; i ++){//n个骰子
            for(int j = i; j <= 6*i; j ++){//总点数
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int k = 1; k <=min(j,6); k ++){//每个骰子的点数
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for(int i = n; i <= 6*n; i ++){
            ans.push_back(dp[n][i] * pow(1.0/6, n));//转换为概率
        }
        return ans;
    }
};

