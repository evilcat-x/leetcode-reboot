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
#include <algorithm>
using namespace std;

class Solution
{
  public:
	int numSquares(int n)
	{
		if (n <= 0)
			return 0;
		static vector<int> dp({0});

		while (dp.size() <= n)
		{
			int m = dp.size();
			int d = INT_MAX;
			for (int i = 1; i * i <= m; ++i)
			{
				d = min(d, dp[m - i * i] + 1);
				if (d == 1)
					break;
			}
			dp.push_back(d);
		}
		return dp[n];
	}
};
