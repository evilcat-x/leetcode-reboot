/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.25%)
 * Total Accepted:    303.2K
 * Total Submissions: 753.5K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int count = 0;
    set<pair<int, pair<int, int>>> v;
    for (int i = 0, h = grid.size(); i < h; i++)
    {
      for (int j = 0, w = grid[i].size(); j < w; j++)
      {
        if (grid[i][j] != '0')
        {
          if (v.find(pair(i, pair(i, j))) == v.end())
            count++;
          visitIsland(v, grid, i, j, h, w);
        }
      }
    }
    return count;
  }
  void visitIsland(set<pair<int, pair<int, int>>> &v,
                   vector<vector<char>> &grid, int row, int col, int h, int w)
  {
    if (v.find(pair(row, pair(row, col))) == v.end() && grid[row][col] == '1')
    {
      v.insert(pair(row, pair(row, col)));
      if (row - 1 >= 0)
        visitIsland(v, grid, row - 1, col, h, w);
      if (row + 1 < h)
        visitIsland(v, grid, row + 1, col, h, w);
      if (col - 1 >= 0)
        visitIsland(v, grid, row, col - 1, h, w);
      if (col + 1 < w)
        visitIsland(v, grid, row, col + 1, h, w);
    }
  }
};
