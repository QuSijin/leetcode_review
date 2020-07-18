//一次哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++)
        {
            
            int com = target-nums[i];
            if(m.find(com)!=m.end())
            {
                return {m[com],i};
            }
            m[nums[i]] = i;//放入元素至map
        }
        return {};

    }
};
