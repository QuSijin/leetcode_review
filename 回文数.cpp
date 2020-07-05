class Solution {
public:
    bool isPalindrome(int x) {
    if(x < 0||x%10==0&&x!=0){//除了 0 以外，所有个位是 0 的数字不可能是回文
        return false;
    }
    int reversenum= 0;
    while(x > reversenum)//当原始数字小于或等于反转后的数字时，意味着已经处理了一半位数的数字了
    {
        reversenum = reversenum * 10 + x % 10;//不断得到反转后的数字
        x/=10;
    }
    return (x==reversenum||x==reversenum/10); //前偶后奇
    }
};
