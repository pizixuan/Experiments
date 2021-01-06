/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0)
            return 0;
        int len = s.length();
        int res = 0;
        for (int i = len-1; i >= 0; i--){
            if (s[i] == ' ' && res == 0)
                continue;
            else if (s[i] != ' ')
                res++;
            else if (s[i] == ' ' && res != 0)
                return res;
        }
        return res;
    }
};
// @lc code=end

