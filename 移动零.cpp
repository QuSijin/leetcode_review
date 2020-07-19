1.交换数组
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
2.暴力法
class Solution{

public:
void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    // Count the zeroes
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(nums[i] == 0){
            cnt++;
        }
    }

    // Make all the non-zero elements retain their original order.
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            ans.push_back(nums[i]);
        }
    }

    // Move all zeroes to the end
    while (cnt--) {
        ans.push_back(0);
    }
    //return ans;
    // Combine the result
    for (int i = 0; i < n; i++) {
        nums[i] = ans[i];
    }
}
};
