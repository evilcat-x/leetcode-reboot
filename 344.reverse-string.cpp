/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (62.77%)
 * Total Accepted:    378.2K
 * Total Submissions: 602.6K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * You may assume all the characters consist of printable ascii
 * characters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 *
 *
 */
#include <vector>
using namespace std;

class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        reverse_recursive(s, 0, s.size() - 1);
    }
    void reverse_recursive(vector<char> &s, int head, int tail)
    {
        if (head >= tail)
            return;
        char tmp;
        tmp = s[tail];
        s[tail] = s[head];
        s[head] = tmp;
        reverse_recursive(s, head - 1, tail - 1);
    }
};
