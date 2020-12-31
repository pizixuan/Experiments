/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        else if (haystack.length() < needle.length())
            return -1;
        int res = -1;
        int store = -1;
        for (int i = 0; i <= haystack.length() - needle.length(); i++){
            if (haystack[i] == needle[0]){  //开始检验
                res = i;
                for (int j = 1; j < needle.length(); j++){
                    if (haystack[i+j] != needle[j]){
                        res = -1;
                        break;
                    }
                }
            }
            if (res != -1)
                break;
        }
        return res;
    }
};
// @lc code=end

