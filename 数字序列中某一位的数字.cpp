class Solution {
public:
    int findNthDigit(int n) {
        // digit表示几位数,start表示几位数的起始数字
        // start*9表示几位数有几个,count=9*start*digit表示几位数总共有几位
        long digit = 1,start = 1,count = 9;
        // 确定所求的数是几位数
        while(n > count){// 1.
            n -= count;
            start *= 10; //1,10,100
            digit += 1;  //1,2,3
            count = 9 * start * digit;
        }
        long num = start + (n-1)/digit;// 2.
        int res = int(to_string(num)[(n-1) % digit] - '0');// 3.所求数位为数字 numnum 的第 (n - 1) \% digit(n−1)%digit 位（ 数字的首个数位为第 0 位）。
        return res;

    }
};

