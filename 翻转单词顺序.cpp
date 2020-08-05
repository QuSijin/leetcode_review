//1.istringstream分割子字符串
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string res, str;
        while(ss >> str)
            res = str + ' ' + res;
        return res.substr(0, res.size() - 1);

    }
};

