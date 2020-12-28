/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针法
        // int fir = 0;
        // int sec = 0;
        // int len = nums.size();
        // if (len == 0)
        //     return 0;
        // int res = 1;
        // for (int i = 0; i < len; i++){
        //     sec = i;
        //     if (nums[fir] == nums[sec])
        //         continue;
        //     else{
        //         fir += 1;
        //         nums[fir] = nums[sec];
        //         res++;
        //     }
        // }
        // return res;
        if (nums.size() < 2)
            return nums.size();
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[j] != nums[i])
                nums[++j] = nums[i];
        }
        return ++j;
    }
};
// @lc code=end

