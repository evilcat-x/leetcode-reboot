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
        queue<int> q;
        int distance = 0;
        q.push(n);
        while (!q.empty())
        {
            for (int i = 0, e = q.size(); i < e; i++)
            {
                int node = q.front();
                q.pop();
                if (node == 0)
                    return distance;
                for (int s = (int)sqrt(node); s > 0; s--)
                {
                    q.push(node - s * s);
                }
            }
            distance++;
        }
        return -1;
    }
};
