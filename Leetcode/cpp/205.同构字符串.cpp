/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        int len = s.length();
        unordered_map<char, char> s2t; //定义两个map
        unordered_map<char, char> t2s;
        for (int i = 0; i < len; i++){
            char eleS = s[i];
            char eleT = t[i];
            if ((s2t.count(eleS) && s2t[eleS] != eleT) || (t2s.count(eleT) && t2s[eleT] != eleS))
                return false;
            s2t[eleS] = eleT;
            t2s[eleT] = eleS;
        }
        return true;
    }
};
// @lc code=end

