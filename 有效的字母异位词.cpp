class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26,0);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            cnt[s.at(i)-'a']++;
            cnt[t.at(i)-'a']--;
        }
        for(int cn:cnt)
        {
            if(cn!=0)
            return false;
        }
        return true;
    }
};
