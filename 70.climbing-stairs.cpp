/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (43.48%)
 * Total Accepted:    359.7K
 * Total Submissions: 827.2K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */
#include <map>
using namespace std;

class Solution
{
  private:
    map<int, int> m;

  public:
    int climbStairs(int n)
    {
        if (m.find(n) != m.end())
            return m[n];
        if (n < 2)
            return 1;
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        m[n] = result;
        return result;
    }
};
