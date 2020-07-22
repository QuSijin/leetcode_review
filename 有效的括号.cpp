class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
        stack <char> st;
        bool isTrue = true;
        for(char ch : s)
        {
            if(m[ch]>=1 && m[ch]<=3) st.push(ch);
            else if(!st.empty() && m[st.top()]==m[ch]-3) st.pop();
            else{
                isTrue = false;
                break;
            }
        }
        if(!st.empty()) isTrue = false;
        return isTrue;
    }
};
