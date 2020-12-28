/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.length();
        for (int i = 0; i < len; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == ')'){
                if (stk.empty())    //先判断是否为空
                    return false;
                else{       //不为空时
                    if (stk.top() != '(')
                        return false;
                    else    //相等则出栈
                        stk.pop();
                }
            }
            else if (s[i] == ']'){
                if (stk.empty())    //先判断是否为空
                    return false;
                else{       //不为空时
                    if (stk.top() != '[')
                        return false;
                    else    //相等则出栈
                        stk.pop();
                }
            }
            else if (s[i] == '}'){
                if (stk.empty())    //先判断是否为空
                    return false;
                else{       //不为空时
                    if (stk.top() != '{')
                        return false;
                    else    //相等则出栈
                        stk.pop();
                }
            }
        }
        if (!stk.empty())   //栈不为空时
            return false;
        return true;
    }
};
// @lc code=end