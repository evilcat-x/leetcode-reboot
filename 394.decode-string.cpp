/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (43.82%)
 * Total Accepted:    88.2K
 * Total Submissions: 201.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 *
 * Given an encoded string, return it's decoded string.
 *
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 */
#include <string>
using namespace std;

class Solution
{
  public:
    string decodeString(string s)
    {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(string &s, int &i)
    {
        string res = "";
        int len = s.length();
        while (i < len && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int repeat = 0;
                while (i < len && isdigit(s[i]))
                    repeat = repeat * 10 + s[i++] - '0';
                i++;
                string decode = decodeString(s, i);
                i++;
                while (repeat-- > 0)
                    res += decode;
            }
            else
                res += s[i++];
        }
        return res;
    }
};
