class Solution {//快速幂
public:
    double myPow(double x, int n) {
         if(x == 0) return 0;//1.=0时
        long b = n;
        double res = 1.0;
        if(b < 0) {//2.<0时
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {//3.>0时
            if((b & 1) == 1) res *= x;//相当于x%2取余数
            x *= x;
            b >>= 1;//向下整除2
        }
        return res;

    }
};

