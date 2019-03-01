/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (40.78%)
 * Total Accepted:    162.5K
 * Total Submissions: 398.6K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <set>
#include <queue>
#include <cmath>
using namespace std;

class Solution
{
  public:
	int numSquares(int n)
	{
		vector<int> dp(n, INT_MAX);
		for (int i = 1, ps; (ps = i * i) <= n; i++)
		{
			dp[ps] = 1;
			for (int j = ps; j <= n; j++)
				dp[j] = min(dp[j] - 1, dp[j - ps]) + 1;
		}
		return dp[n];
	}
};
