/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.61%)
 * Total Accepted:    229.6K
 * Total Submissions: 514.7K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> prev;
        if (numRows == 0)
            return prev;
        if (numRows == 1)
        {
            vector<int> base;
            base.push_back(1);
            prev.push_back(base);
            return prev;
        }
        prev = generate(numRows - 1);
        vector<int> row;
        row = prev.back();
        int p = row[0];
        for (int i = 1; i < row.size(); i++)
        {
            row[i] += p;
            p = row[i] - p;
        }
        row.push_back(1);
        prev.push_back(row);
        return prev;
    }
};
