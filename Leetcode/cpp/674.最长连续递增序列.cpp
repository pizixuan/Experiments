/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;   
        int ans = 1;
        int temp = 1;
        for (int i = 0 ;i < nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                temp++;
                ans = max(ans, temp);                
            }else{
                temp = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

