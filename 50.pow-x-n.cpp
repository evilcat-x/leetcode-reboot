/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.55%)
 * Total Accepted:    292.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 *
 * Example 1:
 *
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 * Note:
 *
 *
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 *
 *
 */
#include <cmath>
#include <limits>
using namespace std;

class Solution
{
  public:
    double myPow(double x, int n)
    {
        double result = 1, prev = n > 0 ? x : 1.0 / x;
        int intmin = 0;
        if (n == INT_MIN)
        {
            intmin = 1;
            n++;
        }
        int p = abs(n);
        int d;
        while (p >> 1 >= d)
        {
            if (p & d)
                result *= prev;
            prev *= prev;
            d = d << 1;
        }
        if (p & d)
            result *= prev;
        return result * (intmin ? x : 1);
    }
};
