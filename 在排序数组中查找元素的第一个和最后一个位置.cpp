//1.调库函数
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end   = upper_bound(nums.begin(), nums.end(), target);
        if (begin == end) return {-1, -1};
        return {(int)(begin - nums.begin()), (int)(end - nums.begin() - 1)};
    }
};
//2.自己调出来的
//class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==target&&ans.size()!=2) ans.push_back(i);
            if(nums[i]==target&&ans.size()==2) {
                ans.pop_back();
                ans.push_back(i);
                }
            else continue;
        }
        if(ans.size()==1)
        {
            for(int j = 0;j<1;j++)
            {
                if(ans[j]!=-1) ans.push_back(ans[j]);
                else continue;
            }

        }
        if(ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return  ans;
    }
};
//3.先从左找，再从右找
class Solution {
    public:
     vector<int> searchRange(vector<int> nums, int target) {
        vector<int> targetRange = {-1, -1};

        // find the index of the leftmost appearance of `target`.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                targetRange[0] = i;
                break;
            }
        }

        // if the last loop did not find any index, then there is no valid range
        // and we return [-1, -1].
        if (targetRange[0] == -1) {
            return targetRange;
        }

        // find the index of the rightmost appearance of `target` (by reverse
        // iteration). it is guaranteed to appear.
        for (int j = nums.size()-1; j >= 0; j--) {
            if (nums[j] == target) {
                targetRange[1] = j;
                break;
            }
        }

        return targetRange;
    }
};


