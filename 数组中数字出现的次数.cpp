//同ii解法一致，要熟悉这种常用解法
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int num : nums) m[num]++;
        for(auto n :m) {
            if(n.second==1)
            {
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};


