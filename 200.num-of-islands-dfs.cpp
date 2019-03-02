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
		for (int i = 0, h = grid.size(); i < h; i++)
		{
			for (int j = 0, w = grid[i].size(); j < w; j++)
			{
				if (grid[i][j] == '1')
				{
					count++;
					grid[i][j] = '0';
					dfs_island(grid, i, j, h,w);
				}
			}
		}
		return count;
  }
  void dfs_island(vector<vector<char>> &grid, int r, int c, int h, int w) {
	  	if (r - 1 >= 0 && grid[r - 1][c] == '1')
		{
			grid[r - 1][c] = '0';
			dfs_island(grid, r - 1, c, h, w);
		}
		if (r + 1 < h && grid[r + 1][c] == '1')
		{
			grid[r + 1][c] = '0';
			dfs_island(grid, r + 1, c, h, w);
		}
		if (c - 1 >= 0 && grid[r][c - 1] == '1')
		{
			grid[r][c - 1] = '0';
			dfs_island(grid, r, c - 1, h, w);
		}
		if (c + 1 < w && grid[r][c + 1] == '1')
		{
			grid[r][c + 1] = '0';
			dfs_island(grid, r, c + 1, h, w);
		}
  }
};
