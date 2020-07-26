class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,hi = nums.size()-1;
        
        while(low<hi)
        {
            int mid = (low+hi)/2;
            if((nums[0]>nums[mid])^(nums[0]>target)^(target>nums[mid]))
            {
                low = mid+1;
            }else{
                hi = mid;
            }
        }
        return low==hi && nums[low]==target ? low :-1;
    }
};
