/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanHash = 
        {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++){
            if(romanHash[s[i]] < romanHash[s[i+1]]){
                res -= romanHash[s[i]];
            }
            else{
                res += romanHash[s[i]];
            }
        }
        res += romanHash[s[s.size()-1]];
        return res;
    }
};
// @lc code=end