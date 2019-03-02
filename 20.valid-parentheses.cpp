/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.87%)
 * Total Accepted:    519K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0, e = s.length(); i < e; i++){
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')') {
                if (st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
            } else if (c == '}') {
                if (st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};

