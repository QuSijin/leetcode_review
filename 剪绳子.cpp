//1.正常解法
class Solution {
public:
    int cuttingRope(int n) {
        // n<=3的情况，m>1必须要分段，例如：3必须分成1、2；1、1、1 ，n=3最大分段乘积是2, 同理2的最大乘积为1
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n+1);
        /*
        下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
        这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
         */
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++) {
            int maxValue = 0;//记录最大的
            //j<=i/2是因为1*3和3*1是一样的，没必要计算在内，只要计算到1*3和2*2就好了
            for(int j = 1; j <= i/2; j++) {
                maxValue = max(maxValue, dp[j] * dp[i-j]);
            }
            dp[i] = maxValue;
        }
        return dp[n];
    }
};
//2.数学解法
class Solution {
public:
    int cuttingRope(int n) {
        return n<=3 ? n-1 : pow(3,n/3)*4/(4-n%3);
    }
};
