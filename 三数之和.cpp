class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> res;
       for(int k=0;k<int (nums.size()-2) && nums[k]<=0;k++)
       {
           int l = k+1;
           int r = nums.size()-1;
           if(k>0 && nums[k]==nums[k-1]) continue;//k>0时前后两个数相等则跳过
           
           while(l<r)
           {
               int sum = nums[k]+nums[l]+nums[r];
               if(sum<0) {while(l<r&&nums[l]==nums[++l]);}
               else if(sum>0) {while(l<r&&nums[r]==nums[--r]);}
               else {
                   res.push_back({nums[l],nums[k],nums[r]});
                   while(l<r&&nums[l]==nums[++l]);
                   while(l<r&&nums[r]==nums[--r]);
               }
           }
       }
       return res;
       
    }
};
int main()
{
    Solution so;
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> b = so.threeSum(a);
    cout << b[0][0] <<'\t';
    cout << b[0][1]<<'\t';
    cout << b[0][2]<<'\t';
    cout << b[1][0]<<'\t';
    cout << b[1][1]<<'\t';
    cout << b[1][2]<<'\t';
    system("pause");
    return 0;
}
