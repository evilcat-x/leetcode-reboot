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
#include <queue>
using namespace std;

class Solution
{
  public:
    string decodeString(string s)
    {
        if (s.find('[') == string::npos)
            return s;
        queue<int> repeat;
        queue<string> output;
        int i = 0;
        int len = s.length();
        while (i < len)
        {
            int r = 0;
            while ('0' <= s[i] && s[i] <= '9')
                r = r * 10 + (s[i++] - '0');
            if (r != 0)
                repeat.push(r);
            if (s[i] == '[')
            {
                int count = 1;
                int mi = i + 1;
                while (mi < len && count > 0)
                {
                    count += s[mi] == '[';
                    count -= s[mi] == ']';
                    mi++;
                }
                output.push(decodeString(s.substr(i + 1, mi - i - 2)));
                i = mi;
            }
            else
            {
                repeat.push(1);
                int mi = i;
                while (mi < len && !('0' <= s[mi] && s[mi] <= '9'))
                    mi++;
                output.push(s.substr(i, mi - i));
                i = mi;
            }
        }
        string result = "";
        while (!repeat.empty())
        {
            string cur = output.front();
            output.pop();
            int e = repeat.front();
            repeat.pop();
            for (int j = 0; j < e; j++)
                result += cur;
        }
        return result;
    }
};
