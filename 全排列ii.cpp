1.手写法
class Solution{
vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        perm(nums,0,nums.size()-1);
        return res;
    }
    void perm(vector<int> nums,int left,int right)
    {
        if(left==right)
        res.push_back(nums);
        for(int i=left;i<=right;i++)
        {
            if(i != left && nums[left]==nums[i]) continue;//quchong
            swap(nums[left],nums[i]);
            perm(nums,left+1,right);
        }
       
    }
};
2.库函数法--next_permmuteUnique
class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
        {
            res.push_back(nums);
        }
        return res;
    }
};
