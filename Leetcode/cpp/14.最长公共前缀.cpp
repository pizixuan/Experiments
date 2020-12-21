/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()){
            return "";
        }
        int len = strs[0].size();       //第一个字符串的长度
        int count = strs.size();        //字符串的个数
        for (int i = 0; i < len; i++){      //第一个字符串的第 i 个字母
            char ch = strs[0][i];       //用于比较
            for (int j = 0; j < count; j++){    //第 j 个字符串
                if (i == strs[j].size() || ch != strs[j][i])        //第一个字符串就是 最长公共前缀 或 ch ！= 对应位置字母
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
// @lc code=end

