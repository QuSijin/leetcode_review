丑数的递推性质： 丑数只包含因子 2, 3, 5，因此有 “丑数 == 某较小丑数 × 某因子”
class Solution {
public:
    int nthUglyNumber(int n) {

        int a = 0,b = 0,c = 0;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<n;i++)
        {
            int n2=dp[a]*2;
            int n3=dp[b]*3;
            int n5=dp[c]*5;
            dp[i] = min(min(n2,n3),n5);
            if(dp[i]==n2) a++;
            if(dp[i]==n3) b++;
            if(dp[i]==n5) c++;
        }
        return dp[n-1];

    }
};
