/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum = nums[0];
        int curNum = nums[0];
        for (int i = 0; i < nums.size(); i++){
            curNum = max(curNum + nums[i], nums[i]);
            maxNum = max(curNum, maxNum);
        }
        return maxNum;
    }
};
// @lc code=end

