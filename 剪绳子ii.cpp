class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2 || n == 3)
        return n - 1;
        long res = 1;
    while (n > 4) {
        //如果n大于4，我们不停的让他减去3
        n = n - 3;
        //计算每段的乘积
        res = res * 3 % 1000000007;//res最大会达到3e9级别，爆掉int
        
    }
    return (int)(res * n % 1000000007);//此处n是不断切完3剩下的数字，res是不断切3后累乘的结果
    }
};
