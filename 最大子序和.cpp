//1.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int pre = 0, maxAns = nums[0];
       for(auto &x :nums)
       {
           pre = max(pre+x,x);
           maxAns = max(maxAns,pre);
       }
       return maxAns;
    }
};
//2.dp的升级版--着重记
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            nums[i] += max(nums[i - 1], 0);
            ans=max(nums[i],ans);
        }
        
        return ans;
    }
};
