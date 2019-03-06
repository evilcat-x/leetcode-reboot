/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (42.10%)
 * Total Accepted:    186.1K
 * Total Submissions: 442.1K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        if (rowIndex == 0)
        {
            prev.push_back(1);
            return prev;
        }
        prev = getRow(rowIndex - 1);
        int p = prev[0];
        for (int i = 1, e = prev.size(); i < e; i++)
        {
            prev[i] += p;
            p = prev[i] - p;
        }
        prev.push_back(1);
        return prev;
    }
};
