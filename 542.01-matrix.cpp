/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (34.68%)
 * Total Accepted:    36.9K
 * Total Submissions: 106.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 * Example 1:
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 *
 * Example 2:
 * Input:
 *
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 * Output:
 *
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 *
 *
 * Note:
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 *
 *
 *
 */
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
  private:
    queue<pair<int, int>> q;
    vector<vector<int>> *mx;
    int height;
    int width;

  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        mx = &(matrix);
        height = matrix.size();
        width = matrix[0].size();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (matrix[i][j] == 1)
                    matrix[i][j] = shortDis(i, j);
            }
        }
        return matrix;
    }
    int shortDis(int r, int c)
    {
        queue<pair<int, int>> q;
        set<pair<int, int>> s;
        if ((*mx)[r][c] == 0)
            return 0;
        q.push(pair(r, c));
        int dis = 0;
        while (!q.empty())
        {
            for (int i = 0, e = q.size(); i < e; i++)
            {
                auto p = q.front();
                q.pop();
                if ((*mx)[p.first][p.second] == 0)
                    return dis;
                p.first--;
                if (p.first >= 0)
                    q.push(p);
                p.first++;
                p.first++;
                if (p.first < height)
                    q.push(p);
                p.first--;
                p.second--;
                if (p.second >= 0)
                    q.push(p);
                p.second++;
                p.second++;
                if (p.second < width)
                    q.push(p);
                p.second--;
            }
            dis++;
        }
        return INT_MAX;
    }
};
