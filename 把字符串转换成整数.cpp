class Solution {
public:
    int strToInt(string str) {
        int i = 0, flag = 1;//符号位
        long res = 0; //默认flag = 1，正数
        while (str[i] == ' ') i ++;//去除开头空格
        if (str[i] == '-') flag = -1;//遇到‘-’变成负号
        if (str[i] == '-' || str[i] == '+') i ++;//略过正负号
        for (; i < str.size() && str[i]>='0' && str[i]<='9'; i ++)  {//小于字符串长度且是数字
            res = res * 10 + (str[i] - '0');//str[i] - '0'才是数字
            if (res >= INT_MAX && flag == 1) return  INT_MAX;
            if (res > INT_MAX && flag == -1) return  INT_MIN;
        } 
        return flag * res;
    }
};


