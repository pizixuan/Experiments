/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        while (right < len){
            if (nums[right] != 0){
                swap(nums[right], nums[left]);
                left++;
            }
            right++;
        }
    }
};
// @lc code=end