/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == val)
                continue;
            nums[j] = nums[i]; //覆盖
            j++;
            res++;
        }
        return res;
    }
};
// @lc code=end

