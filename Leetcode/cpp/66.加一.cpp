/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len-1; i >= 0; i--){
            digits[i]++;
            digits[i] = digits[i] % 10; //(9+1)%10 = 0, 个位数%10 = 0
            if (digits[i] != 0) //没有遇到9，前面的数字不变
                return digits;
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
// @lc code=end

